#include "PersonalTask.h"

PersonalTask::PersonalTask(const std::string& desc, const std::string& date,
    const std::string& loc, bool recurring)
    : Task(desc, date), location(loc), isRecurring(recurring) {
}

PersonalTask::PersonalTask()
	: Task("No description", "No due date"), location("Unknown"), isRecurring(false)
{	
}

void PersonalTask::display() const {
    cout << "[Personal] ID: " << getId()
        << "\nLocation: " << location
        << "\nRecurring: " << (isRecurring ? "Yes" : "No")
        << "\nDue: " << getDueDate()
        << "\nDescription: " << getDescription()
        << "\nCompleted: " << (getIsCompleted() ? "Yes" : "No")
        << "\n--------------------------\n";
}

void PersonalTask::saveToFile(ostream& os) const {
    os << "PERSONAL\n"; 
    os << taskId << '\n';
    os << description << '\n';
    os << dueDate << '\n';
    os << isCompleted << '\n';
    os << location << '\n';
    os << isRecurring << '\n';
}

void PersonalTask::loadFromFile(istream& is) {
    string line;

    getline(is, line);              
    taskId = std::stoi(line);            

    getline(is, description);       
    getline(is, dueDate);           

    getline(is, line);              
    isCompleted = (line == "1" || line == "true");

    getline(is, location);          

    getline(is, line);              
    isRecurring = (line == "1" || line == "true");
}



std::string PersonalTask::toString() const {
    ostringstream oss;
    oss << "[Personal] " << getDescription()
        << " (Location: " << location
        << ", Recurring: " << (isRecurring ? "Yes" : "No") << ")";
    return oss.str();
}


