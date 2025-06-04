#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Task
{
public:
	
	Task(const string& desc, const string& date);
	virtual ~Task() {}
	virtual void display() const = 0;
	virtual void saveToFile(ostream&) const = 0;
	virtual void loadFromFile(istream&) = 0;

	virtual string toString() const = 0;

	int getId() const { return taskId; }
	string getDescription() const { return description; }
	string getDueDate() const { return dueDate; }
	bool getIsCompleted() const { return isCompleted; }

	void setDescription(const string& desc) { description = desc; }
	void setDueDate(const string& date) { dueDate = date; }
	void setIsCompleted(bool completed) { isCompleted = completed; }


	friend ostream& operator<<(std::ostream& os, const Task& task);



protected:
	static int idCounter;
	int taskId;
	string description;
	string dueDate;
	bool isCompleted;

};