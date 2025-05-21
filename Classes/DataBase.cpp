#include "DataBase.h"

DataBase::~DataBase()
{
	for (BaseClass* song : songs)
	{
		delete song;
	}
}

void DataBase::Create(BaseClass::eType type)
{
    BaseClass* obj = nullptr;
    switch (type)
    {
    case BaseClass::eType::ROCK:
        obj = new Rock;
        break;
    case BaseClass::eType::HIP_HOP:
        obj = new HipHop;
        break;
    }
    obj->Read(cout, cin);
    songs.push_back(obj);
}

void DataBase::DisplayAll()
{
	for (BaseClass* song : songs)
	{
		song->Write(cout);
	}

}

void DataBase::Display(const string& name)
{
	for (BaseClass* song : songs)
	{
		if (song->getName() == name)
		{
			song->Write(cout);
		}
	}
}

void DataBase::Display(BaseClass::eType type)
{
	for (BaseClass* song : songs)
	{
		if (song->getGenre() == type)
		{
			song->Write(cout);
		}
	}
}
