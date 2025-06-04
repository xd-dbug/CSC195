#pragma once
#include "Task.h"
class PersonalTask :
	public Task
	{
	public:
		PersonalTask(const string& desc, const string& date, const string& location, bool isRecurring);
		PersonalTask();
		void display() const override;
		void saveToFile(ostream&) const override;
		void loadFromFile(istream&) override;
		string toString() const override;
		virtual ~PersonalTask() {}
		
		string getLocation() const { return location; }
		bool getIsRecurring() const { return isRecurring; }

	protected:
		string location;
		bool isRecurring;

};

