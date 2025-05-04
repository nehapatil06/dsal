#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Patient {
    string name;
    int priority; 

    Patient(const string& name, int priority) : name(name), priority(priority) {}

    bool operator<(const Patient& other) const {
        return priority > other.priority;
    }
};
void displayMenu() {
    cout << "Hospital Management System\n";
    cout << "1. Add Patient\n";
    cout << "2. Serve Patient\n";
    cout << "3. Display Patients\n";
    cout << "4. Exit\n";
}

int main() {
    priority_queue<Patient> patients; // Priority queue to store patients

    int choice;
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name;
                int priority;
                cout << "Enter patient name: ";
                cin >> name;
                cout << "Enter patient priority: ";
                cin >> priority;
                patients.push(Patient(name, priority));
                cout << "Patient added successfully.\n";
                break;
            }
            case 2: {
                if (patients.empty()) {
                    cout << "No patients to serve.\n";
                } else {
                    cout << "Serving patient: " << patients.top().name << endl;
                    patients.pop();
                }
                break;
            }
            case 3: {
                if (patients.empty()) {
                    cout << "No patients in the queue.\n";
                } else {
                    cout << "Patients in the queue:\n";
                    priority_queue<Patient> temp = patients; 
                    while (!temp.empty()) {
                        cout << "Name: " << temp.top().name << ", Priority: " << temp.top().priority << endl;
                        temp.pop();
                    }
                }
                break;
            }
            case 4: {
                cout << "Exiting program.\n";
                break;
            }
            default: {
                cout << "Invalid choice. Please try again.\n";
                break;
            }
        }
    } while (choice != 4);

    return 0;
}

