/*
 * Vehicle.cpp
 *
 *  Created on: 17-Aug-2020
 *      Author: sunbeam
 */

#include "../include/Vehicle.h"

using namespace kd3;
Vehicle::Vehicle()
{}

Vehicle::Vehicle(string company=" ",string model=" ",string number =" ")
{
	this->company=company;
	this->model=model;
	this->number=number;
}

const string& Vehicle::getCompany() const
{
	return company;
}

void Vehicle::setCompany(const string& company)
{
	this->company = company;
}

const string& Vehicle::getModel() const
{
	return model;
}

void Vehicle::setModel(const string& model)
{
	this->model = model;
}

const string& Vehicle::getNumber() const
{
	return number;
}

void Vehicle::setNumber(const string& number)
{
	this->number = number;
}
void Vehicle::printVehicle()
{

	cout<<" "<<this->company<<"  "<<this->model<<"  "<<this->number<<endl;
}
Vehicle::~Vehicle()
{

}





