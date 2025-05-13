#include "Task.h"
using namespace std;


int Task::idCounter = 1; 

Task::Task(string title, string description, string assignedTo) {
	this->id = idCounter++;
	this->title = title;
	this->description = description;
	this->assignedTo = assignedTo;
	this->status = "Pending";
}
	
	int Task::getId() const { return id; }
	string Task::getTitle() const { return title; }
	string Task::getDescription() const { return description; }
	string Task::getAssignedTo() const { return assignedTo; }
	string Task::getStatus() const { return status; }

	void Task::setTitle(string title) { this->title = title; }
	void Task::setDescription(string description) { this->description = description; }
	void Task::setAssignedTo(string assignedTo) { this->assignedTo = assignedTo; }
	void Task::setStatus(string status) { this->status = status; }

	
	string Task::toString() const {
		std::ostringstream oss;
		oss << "[" << id << "] " << title << " (" << status << ") - Assigned to: " << assignedTo;
		return oss.str();
	}

