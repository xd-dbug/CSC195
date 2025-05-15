#include "TeamTaskTracker.h"
#include <iostream>
#include <limits>
using namespace std;

void TeamTaskTracker::run() {
    while (true) {
        cout << "\nTeam Task Tracker\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Update Task Status\n";
        cout << "4. Delete Task\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";

        int choice;
        cin >> choice;
        clearInput();

        switch (choice) {
        case 1:
            addTask();
            break;
        case 2:
            viewTasks();
            break;
        case 3:
            updateTaskStatus();
            break;
        case 4:
            deleteTask();
            break;
        case 5:
             cout << "Exiting...\n";
            return;
        default:
             cout << "Invalid choice\n";
        }
    }
}

void TeamTaskTracker::addTask() {
     string title, description, assignedTo;

     cout << "Enter task title: ";
     getline(cin, title);

     cout << "Enter task description: ";
     getline(cin, description);

     cout << "Enter assigned person: ";
     getline(cin, assignedTo);

    tasks.emplace_back(title, description, assignedTo);
     cout << "Task added successfully!\n";
}

void TeamTaskTracker::viewTasks() {
    if (tasks.empty()) {
         cout << "No tasks available.\n";
        return;
    }

     cout << "\nTask List:\n";
    for (const auto& task : tasks) {
         cout << task.toString() << "\n";
    }
}

void TeamTaskTracker::updateTaskStatus() {
    int id;
     cout << "Enter task ID to update: ";
     cin >> id;
    clearInput();

    for (auto& task : tasks) {
        if (task.getId() == id) {
             string newStatus;
             cout << "Enter new status (Pending/In Progress/Completed): ";
             getline( cin, newStatus);
            task.setStatus(newStatus);
             cout << "Task status updated!\n";
            return;
        }
    }
     cout << "Task ID not found.\n";
}

void TeamTaskTracker::deleteTask() {
    int id;
     cout << "Enter task ID to delete: ";
     cin >> id;
    clearInput();

    for (auto i = tasks.begin(); i != tasks.end(); ++i) {
        if (i->getId() == id) {
            tasks.erase(i);
             cout << "Task deleted successfully!\n";
            return;
        }
    }
     cout << "Task ID not found.\n";
}

void TeamTaskTracker::clearInput() {
     cin.ignore( numeric_limits< streamsize>::max(), '\n');
}
