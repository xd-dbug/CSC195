#include "Task.h"

int Task::idCounter = 0;

Task::Task(const string& desc, const string& date) :
	taskId(++idCounter), description(desc), dueDate(date), isCompleted(false) {}

ostream& operator<<(std::ostream& os, const Task& task)
{
	os << task.toString();
	return os;
}
