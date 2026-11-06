#include "Investigation.h"

Person::Person(string name, string role)
    : name(name), role(role) {
}

Person::~Person() {
}

string Person::getName() const {
    return name;
}

string Person::getRole() const {
    return role;
}

void Person::displayInfo() const {
    cout << "Name: " << name << endl;
    cout << "Role: " << role << endl;
}


Evidence::Evidence(int id, string name, string location, string desc)
    : evidenceID(id), name(name),
      locationFound(location), description(desc) {
}

Evidence::~Evidence() {
}

int Evidence::getID() const {
    return evidenceID;
}

string Evidence::getName() const {
    return name;
}

void Evidence::inspect() const {
    cout << endl << "[Evidence ID: " << evidenceID << "] " << name << endl;
    cout << "   -> Found in: " << locationFound << endl;
    cout << "   -> Details: " << description << endl;
}


Suspect::Suspect(string name, string relation, string alibi, bool guilty)
    : Person(name, relation), alibi(alibi), isGuilty(guilty) {
}

Suspect::~Suspect() {
}

string Suspect::getAlibi() const {
    return alibi;
}

bool Suspect::checkGuilt() const {
    return isGuilty;
}

void Suspect::displayInfo() const {
    cout << "Suspect: " << name << endl;
    cout << "Relation: " << getRole() << endl;
    cout << "Alibi: " << alibi << endl;
}


Witness::Witness(string name, string statement)
    : Person(name, "Witness"), statement(statement) {
}

Witness::~Witness() {
}

string Witness::getStatement() const {
    return statement;
}

void Witness::displayInfo() const {
    cout << "Witness: " << name << endl;
    cout << "Statement: " << statement << endl;
}


DetectiveGame::DetectiveGame() {


    suspectList.push_back(
        Suspect("Lady Margaret", "Wife",
        "I was busy greeting guests in the grand hall all evening.", false)
    );

    suspectList.push_back(
        Suspect("Lord Richard", "Brother",
        "I was standing near the balcony discussing politics.", false)
    );

    suspectList.push_back(
        Suspect("Victor", "Secretary",
        "I was alone in the archive room reviewing ledger records the whole time.", false)
    );

    suspectList.push_back(
        Suspect("Dr. Elena", "Family Doctor",
        "I was helping the chef in the kitchen at first, then spent the rest of the time working in the archive room.", true)
    );

    suspectList.push_back(
        Suspect("Peter", "Butler",
        "I was serving drinks and managing the dining hall with the guests all the time.", false)
    );



    evidenceList.push_back(
        Evidence(101, "The Bloody Kitchen Knife",
        "Duke's Office",
        "The murder weapon used to stab the Duke. Wiped clean of prints.")
    );

    evidenceList.push_back(
        Evidence(102, "Kitchen Inventory Match Log",
        "Kitchen",
        "Forensic analysis confirms the murder weapon perfectly matches the missing knife slot from the kitchen block.")
    );


    witnessList.push_back(
        Witness("Head Chef",
        "He saw Dr. Elena in the kitchen, but did not see the other suspects there.")
    );

    witnessList.push_back(
        Witness("The Ambassador",
        "He confirms that Lord Richard was near the balcony.")
    );

    witnessList.push_back(
        Witness("Grand Hall Guests",
        "They confirm that Lady Margaret was greeting guests.")
    );

    witnessList.push_back(
        Witness("Dining Hall Staff",
        "They confirm that Peter was serving drinks in the dining hall.")
    );
}

DetectiveGame::~DetectiveGame() {
    cout << endl << "[System] Investigation data cleared." << endl;
}


void DetectiveGame::displayPersonInfo(const Person& person) const {
    person.displayInfo();
}

void DetectiveGame::showEvidence() const {

    cout << endl << "================= CASE EVIDENCE =================" << endl;

    for (const auto& ev : evidenceList) {
        ev.inspect();
        cout << "-------------------------------------------------" << endl;
    }
}

void DetectiveGame::showEvidence(int id) const {

    bool found = false;

    cout << endl << "================= SEARCH EVIDENCE =================" << endl;

    for (const auto& ev : evidenceList) {

        if (ev.getID() == id) {
            ev.inspect();
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Evidence not found!" << endl;
    }
}


void DetectiveGame::showSuspects() const {

    cout << endl << "================= LIST OF SUSPECTS =================" << endl;

    int index = 1;

    for (const auto& s : suspectList) {

        cout << endl << index++ << ". ";
        displayPersonInfo(s);
    }
}


void DetectiveGame::showAlibis() const {

    cout << endl << "================= SUSPECT ALIBIS =================" << endl;

    for (const auto& s : suspectList) {

        cout << "- " << s.getName() << ": \""
             << s.getAlibi() << "\"" << endl;
    }

    cout << endl
         << "[Butler's Note]: Peter the Butler confirms firmly "
         << "that he was with the guests in the dining hall the entire time."
         << endl;
}


void DetectiveGame::showWitnessStatements() const {

    cout << endl << "================= WITNESS TESTIMONIES =================" << endl;

    for (const auto& w : witnessList) {

        cout << endl;
        displayPersonInfo(w);
        cout << "-------------------------------------------------" << endl;
    }

    cout << endl
         << "Victor's alibi cannot be verified because he claims "
         << "he was alone in the archive room!" << endl;
}


void DetectiveGame::showHelpHint() const {

    cout << endl << "================= DETECTIVE HINT / HELP =================" << endl;

    cout << "- Head Chef's Statement: He confirms that he did not see "
         << "any of the suspects except Dr. Elena in the kitchen. "
         << "All kitchen staff share this exact statement." << endl;

    cout << "- Archive Timeline Conflict: Both Victor and Dr. Elena "
         << "claim they were in the archive room, but both confirm "
         << "they did NOT see each other there at all!" << endl;
}


void DetectiveGame::makeAccusation(int choice) const {

    if (choice < 1 || choice > static_cast<int>(suspectList.size())) {

        cout << endl << "[ERROR] Invalid choice." << endl;
        return;
    }

    const Suspect& chosen = suspectList[choice - 1];

    cout << endl << "=================== FINAL ACCUSATION ===================" << endl;

    cout << "You point your finger at "
         << chosen.getName() << " ("
         << chosen.getRole() << ")!" << endl;

    if (chosen.checkGuilt()) {

        cout << endl
             << "[VICTORY] Case Solved! Dr. Elena breaks down and confesses!"
             << endl;

        cout << "Reasoning: She used the kitchen assistance as a fake alibi "
             << "to steal the knife, stabbed the Duke, and tried to frame "
             << "Victor using the archive loophole. Masterclass detective work!"
             << endl;
    }

    else {

        cout << endl
             << "[GAME OVER] Wrong Accusation! "
             << chosen.getName()
             << " strongly objects and proves their innocence!"
             << endl;

        cout << "Reasoning for failure: You fell for the trap! "
             << chosen.getName()
             << " had solid witness backing and an unbreakable alibi. "
             << "The true killer slipped away..." << endl;
    }

    cout << "========================================================" << endl;
}
