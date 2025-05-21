#pragma once
#include <string>
#include <iostream>
using namespace std;
class BaseClass
{
public:

	enum class eType
	{
		ROCK,
		HIP_HOP
	};
	virtual void Read(ostream& ostream, istream& istream);
	virtual void Write(ostream& ostream);

	string getName();
	string getArtist();
	
	virtual eType getGenre() = 0;

protected:
	string name;
	string artist;
	

};

