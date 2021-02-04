/*
 * ServiceStation.h
 *
 *  Created on: 18-Aug-2020
 *      Author: sunbeam
 */

#ifndef SERVICESTATION_H_
#define SERVICESTATION_H_

#include<iostream>
using namespace std;
#include<list>
#include <fstream>
#include <sstream>
#include"Bill.h"
#include"Customer.h"
#include"Exception.h"
namespace kd3{

class ServiceStation {
private:
	list<Bill> billList;
	list<Customer>custList;
	string name;
private:
	ServiceStation();
	ServiceStation(const string &name);
	ServiceStation(const ServiceStation &other);
public:
	double computeCash();
	void displayCustomer();
	Customer* findCustomer(const string number)throw(Exception);
	const list<Customer>& getCustmerList() const;
	const list<Bill>& getBillList() const;
	void setBillList(const Bill& billList);
	void setCustList(const list<Customer>& custList);
	const string& getName() const;
	void setName(const string& name);
	void handleServiceRequest();
	void loadCustomerDetail();
	void newCustomer();
	void storeCustomerDetail();
	static ServiceStation& getInstance();
	void saveBill(string mobile);
	void loadBillDetail(vector<string> &temp);
	~ServiceStation();
};

}

#endif /* SERVICESTATION_H_ */
