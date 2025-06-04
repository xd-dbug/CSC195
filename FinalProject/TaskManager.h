#pragma once
#include <vector>
#include <memory>
#include <string>
#include "Task.h"

class TaskManager {
public:
    void addTask(unique_ptr<Task> task);
    void removeTaskById(int id);
    void displayAll() const;
    void saveAllToFile(const string& filename) const;
    void loadAllFromFile(const string& filename);
    void markTaskComplete(int id);


private:
    std::vector<std::unique_ptr<Task>> tasks;
};

