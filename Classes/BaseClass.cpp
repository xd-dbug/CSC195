#include "BaseClass.h"

void BaseClass::Read(ostream& ostream, istream& istream)
{
	ostream << "Enter the name of the song: ";
	istream >> name;
	ostream << "Enter the artist name: ";
	istream >> artist;
}

void BaseClass::Write(ostream& ostream)
{
	ostream << "Name: " << name << endl;
	ostream << "Artist: " << artist << endl;
}

string BaseClass::getName()
{
	return string();
}

string BaseClass::getArtist()
{
	return string();
}
