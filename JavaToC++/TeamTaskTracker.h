#include <vector>
#include "Task.h"
using namespace std;

class TeamTaskTracker {
private:
    vector<Task> tasks;
    void addTask();
    void viewTasks();
    void updateTaskStatus();
    void deleteTask();
    void clearInput();

public:
    void run();
};