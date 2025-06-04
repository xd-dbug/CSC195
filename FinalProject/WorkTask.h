#pragma once
#include "Task.h"
class WorkTask :
	public Task
{
public:
	
    WorkTask(const string& desc, const string& date, const string& project, int priorityLevel);
	WorkTask();
    void display() const override;
    void saveToFile(ostream&) const override;
    void loadFromFile(istream&) override;
    string toString() const override;

	int getPriority() const { return priorityLevel; }

	string getProjectName() const { return projectName; }


protected:
	int priorityLevel;
    string projectName;
	
};

