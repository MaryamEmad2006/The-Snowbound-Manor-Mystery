#include <iostream>
#include "Investigation.h"
using namespace std;
int main() {

    DetectiveGame game;
    int choice = 0;

    cout << "=========================================================" << endl;
    cout << "       THE WINTERBELL ESTATE MURDER: DETECTIVE GAME      " << endl;
    cout << "=========================================================" << endl;

    cout << "Duke Winterbell was found dead stabbed with a knife." << endl;
    cout << "Examine the clues, interrogate the statements, and find the killer!" << endl;

    do {

        cout << endl << "-------------- INVESTIGATION MENU --------------" << endl;

        cout << "1. View All Evidence" << endl;
        cout << "2. View Suspects List" << endl;
        cout << "3. View Suspect Alibis" << endl;
        cout << "4. View Witness Testimonies" << endl;
        cout << "5. Detective Hint / Help" << endl;
        cout << "6. Make Final Accusation" << endl;
        cout << "7. Exit Investigation" << endl;
        cout << "8. Search Evidence by ID" << endl;

        cout << "Enter your choice (1-8): ";
        cin >> choice;

        if (cin.fail()) {

            cin.clear();
            cin.ignore(10000, '\n');

            cout << endl << "[ERROR] Please enter a valid number." << endl;

            continue;
        }

        switch (choice) {

            case 1:

                game.showEvidence();
                break;

            case 2:

                game.showSuspects();
                break;

            case 3:

                game.showAlibis();
                break;

            case 4:

                game.showWitnessStatements();
                break;

            case 5:

                game.showHelpHint();
                break;

            case 6: {

                int suspectNum;

                game.showSuspects();

                cout << endl << "Choose the murderer (1-5): ";
                cin >> suspectNum;

                if (cin.fail()) {

                    cin.clear();
                    cin.ignore(10000, '\n');

                    cout << "[ERROR] Invalid input." << endl;
                    break;
                }

                if (suspectNum < 1 || suspectNum > 5) {

                    cout << "[ERROR] Choose a number from 1 to 5." << endl;
                    break;
                }

                game.makeAccusation(suspectNum);

                choice = 7;

                break;
            }

            case 7:

                cout << endl
                     << "Leaving the manor unsolved... Goodbye, Detective."
                     << endl;

                break;

            case 8: {

                int evidenceID;

                cout << "Enter Evidence ID (101 or 102): ";
                cin >> evidenceID;

                if (cin.fail()) {

                    cin.clear();
                    cin.ignore(10000, '\n');

                    cout << "[ERROR] Invalid input." << endl;
                    break;
                }

                game.showEvidence(evidenceID);

                break;
            }

            default:

                cout << endl << "[ERROR] Invalid choice. Try again." << endl;
        }

    } while (choice != 7);

    return 0;
}
