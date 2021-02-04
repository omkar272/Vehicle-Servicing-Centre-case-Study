/*
 * ServiceRequest.h
 *
 *  Created on: 20-Aug-2020
 *      Author: sunbeam
 */


#ifndef SERVICEREQUEST_H_
#define SERVICEREQUEST_H_

#include<iostream>
using namespace std;
#include"Service.h"
#include<list>
namespace kd3 {

class ServiceRequest {
	string customerName;
	list<Service*>serviceList;
	string vehicleNumber;
public:
	ServiceRequest();
	~ServiceRequest();
	void addItem(Service *service);
	const string& getCustomerName() const;
	void setCustomerName(const string& customerName);
	const list<Service*>& getServiceList() const;
	void setServiceList(Service* services);
	const string& getVehicleNumber() const;
	void setVehicleNumber(const string& vehicleNumber);
	void processRequest();
};

} /* namespace kd3 */

#endif /* SERVICEREQUEST_H_ */
