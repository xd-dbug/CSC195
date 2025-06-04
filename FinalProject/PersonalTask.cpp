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

void PersonalTask::saveToFile(std::ostream& os) const {
    os << "PERSONAL\n"; 
    os << taskId << '\n';
    os << description << '\n';
    os << dueDate << '\n';
    os << isCompleted << '\n';
    os << location << '\n';
    os << isRecurring << '\n';
}

void PersonalTask::loadFromFile(std::istream& is) {
    getline(is, description);
    getline(is, dueDate);
    is >> isCompleted;
    is.ignore();
    std::getline(is, location);
    is >> isRecurring;
    is.ignore();
}

std::string PersonalTask::toString() const {
    ostringstream oss;
    oss << "[Personal] " << getDescription()
        << " (Location: " << location
        << ", Recurring: " << (isRecurring ? "Yes" : "No") << ")";
    return oss.str();
}


