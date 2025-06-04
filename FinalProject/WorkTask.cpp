#include "WorkTask.h"

WorkTask::WorkTask(const string& desc, const string& date, const string& project, int priorityLevel) :
	Task(desc, date), projectName(project), priorityLevel(priorityLevel)
{

}

WorkTask::WorkTask()
	: Task("No description", "No due date"), projectName("Unknown"), priorityLevel(1)
{
}

void WorkTask::display() const
{
    cout<< "[Work] ID: " << getId()
		<< "\nProject: " << projectName
		<< "\nPriority: " << priorityLevel
        << "\nDue: " << getDueDate()
        << "\nDescription: " << getDescription()
        << "\nCompleted: " << (getIsCompleted() ? "Yes" : "No")
        << "\n--------------------------\n";
}

void WorkTask::saveToFile(ostream& os) const
{
    os << "WORK\n"; 
    os << taskId << '\n';
    os << description << '\n';
    os << dueDate << '\n';
    os << isCompleted << '\n';
    os << projectName << '\n';
    os << priorityLevel << '\n';
}

void WorkTask::loadFromFile(istream& is) {
    string line;

    getline(is, line);
    taskId = std::stoi(line);

    getline(is, description);
    getline(is, dueDate);

    getline(is, line);
    isCompleted = (line == "1" || line == "true");

    getline(is, projectName);

    getline(is, line);
    priorityLevel = stoi(line);
}

string WorkTask::toString() const
{
    ostringstream oss;
    oss << "[Work] " << getDescription()
        << " (Project: " << projectName
        << ", Priority: " << priorityLevel << ")";
    return oss.str();
}
