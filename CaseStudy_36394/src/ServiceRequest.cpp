/*
 * ServiceRequest.cpp
 *
 *  Created on: 20-Aug-2020
 *      Author: sunbeam
 */

#include "../include/ServiceRequest.h"

using namespace kd3 ;

ServiceRequest::ServiceRequest(){}

void ServiceRequest::addItem(Service *service){}

const string& kd3::ServiceRequest::getCustomerName() const
{
	return customerName;
}

void kd3::ServiceRequest::setCustomerName(const string& customerName)
{
	this->customerName = customerName;
}

const list<Service*>& kd3::ServiceRequest::getServiceList() const
{
	return serviceList;
}

void kd3::ServiceRequest::setServiceList(Service* services)
{
	this->serviceList.push_back(services);
}

const string& kd3::ServiceRequest::getVehicleNumber() const
{
	return vehicleNumber;
}

void kd3::ServiceRequest::setVehicleNumber(const string& vehicleNumber)
{
	this->vehicleNumber = vehicleNumber;
}

ServiceRequest::~ServiceRequest()
{}

