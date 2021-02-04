/*
 * Customer.h
 *
 *  Created on: 17-Aug-2020
 *      Author: sunbeam
 */

#ifndef CUSTOMER_H_
#define CUSTOMER_H_
#include<iostream>
using namespace std;
#include <fstream>
#include <sstream>
#include<vector>
#include <iomanip>
#include "Vehicle.h"
#include "Bill.h"
namespace kd3 {

class Customer
{	private:
		string address;
		string mobile;
		string name;
		vector<Vehicle> vehicleList;

public:
	Customer();
	Customer(string address,string mobile, string name);

	const string& getAddress() const;
	void setAddress(const string& address);
	const string& getMobile() const;
	void setMobile(const string& mobile);
	const string& getName() const;
	void setName(const string& name);
	void displayVehicles();
	int getNoOfVehicles();
	void loadCustomer(vector <Customer> &cs);
	void saveCustomer(vector <Customer> &cs);
	vector<Vehicle>& getVehicleList();
	void newVehicle();
	void setVehicleList(Vehicle v1);
	void printRecord(vector<Customer>&cs);
	void payBill(Bill &bill);
	void input();
	~Customer();

	friend istream& operator>>(istream &in,Customer &other)
	{
		cout<<"		Name of Customer : ";
		getline (in,other.name);
		cout<<"		Mobile Number : ";
		getline (in,other.mobile);
		cout<<"		Address : ";
		getline (in,other.address);
		return in;
	}

	friend ostream& operator<<(ostream &out,Customer &other)
	{
		//out<<"Name    :	"<<other.name<<endl;
		//out<<"Mobile  :	"<<other.mobile<<endl;
		//out<<"Address :	"<<other.address<<endl;
		cout<<endl<<"Existing Vehicles of Customer in Record --"<<endl;
		for(unsigned i=0;i<other.vehicleList.size();i++)
			other.vehicleList[i].printVehicle();
		return out;
	}

};

//using namespace kd3;


} /* namespace kd3 */

#endif /* CUSTOMER_H_ */
