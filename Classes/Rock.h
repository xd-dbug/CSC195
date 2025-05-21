#pragma once
#include "BaseClass.h"
class Rock : public BaseClass
{
public:
	void Read(ostream& ostream, istream& istream) override;
	void Write(ostream& ostream) override;
	eType getGenre() override { return eType::ROCK; }
protected:
	string band;
};
