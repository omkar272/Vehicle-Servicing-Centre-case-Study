
#include "../include/Part.h"

using namespace kd3;

Part::Part(){}
Part::Part(int partNo,string desc= " ",double rate=0)
{	this->partNo=partNo;
	this->desc=desc;
	this->rate=rate;

}

const string& Part::getDesc() const
{
	return desc;
}

double Part::getRate() const
{
	return rate;
}

int Part::getPartNo() const
{
	return this->partNo;
}

void Part::setPartNo(int partNo)
{
	 this->partNo=partNo;
}

void Part::input()
{
	cout<<endl<<"Part description  : ";
	cin>>this->desc;
	cout<<"Enter Prize : ";
	cin>>this->rate;
}

void Part::display()
{
	cout<<"		"<<this->partNo<<") "<<this->desc<<"		"<<this->rate<<" /Rs"<<endl;
}

void Part::setDesc(const string& desc)
{
	this->desc = desc;
}



void Part::setRate(double rate)
{
	this->rate = rate;
}

Part::~Part() {}


