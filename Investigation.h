#ifndef INVESTIGATION_H
#define INVESTIGATION_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
protected:
    string name;

private:
    string role;

public:
    Person(string name, string role);
    virtual ~Person();

    string getName() const;
    string getRole() const;

    virtual void displayInfo() const;
};

class Evidence {
private:
    int evidenceID;
    string name;
    string locationFound;
    string description;

public:
    Evidence(int id, string name, string location, string desc);
    ~Evidence();

    int getID() const;
    string getName() const;

    void inspect() const;
};

class Suspect : public Person {
private:
    string alibi;
    bool isGuilty;

public:
    Suspect(string name, string relation, string alibi, bool guilty);
    ~Suspect() override;

    string getAlibi() const;
    bool checkGuilt() const;

    void displayInfo() const override;
};

class Witness : public Person {
private:
    string statement;

public:
    Witness(string name, string statement);
    ~Witness() override;

    string getStatement() const;

    void displayInfo() const override;
};

class DetectiveGame {
private:
    vector<Evidence> evidenceList;
    vector<Suspect> suspectList;
    vector<Witness> witnessList;

    void displayPersonInfo(const Person& person) const;

public:
    DetectiveGame();
    ~DetectiveGame();

    void showEvidence() const;
    void showEvidence(int id) const;

    void showSuspects() const;
    void showAlibis() const;
    void showWitnessStatements() const;
    void showHelpHint() const;
    void makeAccusation(int choice) const;
};

#endif
