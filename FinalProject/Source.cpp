#include <iostream>
#include "TaskManager.h"
#include "WorkTask.h"
#include "PersonalTask.h"

int main() {
    TaskManager* manager = new TaskManager;
    int choice;

    do {
        cout << "\n--- Task Manager ---\n";
        cout << "1. Add Work Task\n";
        cout << "2. Add Personal Task\n";
        cout << "3. Display All Tasks\n";
        cout << "4. Remove Task by ID\n";
        cout << "5. Save to File\n";
        cout << "6. Load from File\n";
        cout << "7. Mark Task as Completed\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string desc, date, project;
            int priority;

            cout << "Description: ";
            getline(cin, desc);
            cout << "Due Date: ";
            getline(cin, date);
            cout << "Project Name: ";
            getline(cin, project);
            cout << "Priority Level (1-5): ";
            cin >> priority;
            cin.ignore();

            manager->addTask(std::make_unique<WorkTask>(desc, date, project, priority));
        }
        else if (choice == 2) {
            std::string desc, date, location;
            bool recurring;

            cout << "Description: ";
            getline(cin, desc);
            cout << "Due Date: ";
            getline(cin, date);
            cout << "Location: ";
            getline(cin, location);
            cout << "Is it recurring? (1 = Yes, 0 = No): ";
            cin >> recurring;
            cin.ignore();

            manager->addTask(std::make_unique<PersonalTask>(desc, date, location, recurring));
        }
        else if (choice == 3) {
            manager->displayAll();
        }
        else if (choice == 4) {
            int id;
            cout << "Enter Task ID to remove: ";
            cin >> id;
            cin.ignore();
            manager->removeTaskById(id);
        }
        else if (choice == 5) {
            manager->saveAllToFile("tasks.txt");
        }
        else if (choice == 6) {
            manager->loadAllFromFile("tasks.txt");
        }

        else if (choice == 7) {
            int id;
            cout << "Enter Task ID to mark complete: ";
            cin >> id;
            cin.ignore();
            manager->markTaskComplete(id);
        }

    } while (choice != 0);

	delete manager;
    cout << "Exiting...\n";
    return 0;
}
