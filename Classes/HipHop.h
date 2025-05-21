#pragma once
#include "BaseClass.h"
class HipHop : public BaseClass
{
public:
	HipHop() : BaseClass() {};
    HipHop(bool isExplicit) : BaseClass(), isExplicit(isExplicit) {}
	void Read(ostream& ostream, istream& istream) override;
	void Write(ostream& ostream) override;
	eType getGenre() override { return eType::HIP_HOP; }
	
protected:
	bool isExplicit;
};

