#include "TaskManager.h"
#include "WorkTask.h"
#include "PersonalTask.h"
#include <fstream>
#include <iostream>

void TaskManager::addTask(unique_ptr<Task> task) {
    tasks.push_back(move(task));
}

void TaskManager::removeTaskById(int id) {
    auto it = remove_if(tasks.begin(), tasks.end(),[id](const std::unique_ptr<Task>& t) { return t->getId() == id; });
    tasks.erase(it, tasks.end());
}
void TaskManager::displayAll() const {
	for (const auto& task : tasks) {
		task->display();
	}
}

void TaskManager::saveAllToFile(const string& filename) const {
	ofstream out(filename);
	for (const auto& task : tasks) {
		task->saveToFile(out); 
	}
}


void TaskManager::loadAllFromFile(const string& filename) {
    tasks.clear();
    ifstream in(filename);
    string type;

    while (getline(in, type)) {
        unique_ptr<Task> task;

        if (type == "WORK") {
            task = make_unique<WorkTask>();
        }
        else if (type == "PERSONAL") {
            task = make_unique<PersonalTask>();
        }

        if (task) {
            task->loadFromFile(in);
            tasks.push_back(std::move(task));
        }
    }
    cout << "Tasks loaded from " << filename << ".\n";
}

void TaskManager::markTaskComplete(int id) {
    for (auto& task : tasks) {
        if (task->getId() == id) {
            task->setIsCompleted(true);
            std::cout << "Task ID " << id << " marked as completed.\n";
            return;
        }
    }
    cout << "Task ID " << id << " not found.\n";
}

