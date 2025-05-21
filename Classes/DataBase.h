#pragma once
#include "BaseClass.h"
#include "Rock.h"
#include "HipHop.h"
#include <vector>
using namespace std;
class DataBase
{
public:
	~DataBase();
	void Create(BaseClass :: eType type);
	void DisplayAll();
	void Display(const string& name);
	void Display(BaseClass::eType type);
private:
	vector<BaseClass*> songs;
};

