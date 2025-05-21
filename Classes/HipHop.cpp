#include "HipHop.h"


void HipHop::Read(ostream& ostream, istream& istream)
{
	BaseClass::Read(ostream, istream);
	ostream << "Is the song explicit? (1 for yes, 0 for no): ";
	istream >> isExplicit;
	
	
	
}

void HipHop::Write(ostream& ostream)
{
	BaseClass::Write(ostream);
	ostream << "Explicit: " << (isExplicit ? "Yes" : "No") << endl;
}


