#include "Rock.h"

void Rock::Read(ostream& ostream, istream& istream)
{
	BaseClass::Read(ostream, istream);
	ostream << "Enter the band name: ";
	ostream << "Enter the artist name: ";
	ostream << "Enter the song name: ";
	istream >> band;
	istream >> artist;
	istream >> name;
}

void Rock::Write(ostream& ostream)
{
	BaseClass::Write(ostream);
	ostream << "Band: " << band << endl;
	ostream << "Artist: " << artist << endl;
	ostream << "Song: " << name << endl;
}
