/*
 * Customer.cpp
 *
 *  Created on: 17-Aug-2020
 *      Author: sunbeam
 */

#include "../include/Customer.h"

using namespace kd3;

Customer::Customer()
{

	this->address=" ";
	this->mobile="";
	this->name=" ";
}

Customer::Customer(string address=" ",string mobile=" ", string name=" ")
{
	this->address=address;
	this->mobile=mobile;
	this->name=name;
}

void Customer::displayVehicles()
{
		int j=1;
	for(unsigned i=0;i<this->vehicleList.size();i++)
	{	cout<<"		"<<j<<")";
		this->vehicleList[i].printVehicle();
		j++;
	}
	cout<<endl;
}
const string& Customer::getAddress() const
{
	return address;
}


const string& Customer::getMobile() const
{
	return mobile;
}


const string& Customer::getName() const
{
	return name;
}


vector<Vehicle>& Customer::getVehicleList()
{
	return this->vehicleList;
}


void Customer::payBill(Bill &bill)
{
	double paid;
	cout<<endl<<"		Enter Amount to be paid : ";
	cin>>paid;
	bill.setPaidAmount(paid);

}

void Customer::input()
{
		unsigned int mob;
			cin.ignore();
			cout<<"		Name of Customer : ";
			getline (cin,this->name);
			cout<<"		Mobile Number : ";
			cin>>this->mobile;
			cin.ignore();
			cout<<"		Address : ";
			getline (cin,this->address);
			cout<<endl;
}

void Customer::loadCustomer(vector <Customer> &cs)
{
	ifstream fp,fpVehicle;
	fp.open("Customer.csv");
			string line;
			if(!fp)
			{
				cerr<<"Failed to open File "<<endl;
				return;
			}
			while(getline(fp,line))
			{
				unsigned i;
				stringstream str(line);
				string token[3];
				for(i=0;i<3;i++)
				{
					getline(str,token[i],',');
				}
				Customer obj(token[0],token[1],token[2]);
				{
					i=0;
					fpVehicle.open("Vehicle.csv");
		            if(!fpVehicle)
		            {
		                perror("failed to open vehicle file");
		                return;
		            }
		            while(getline(fpVehicle, line))
		            {

		                stringstream str(line);

		                string token[4];
		                string company,model,number, mobile;
		                for(int q=0;q<4;q++)
		                {
		                	getline(str,token[q],',');

		                }
		                company=token[0];
		                model=token[1];
		                number=token[2];
		                mobile=token[3];

						Vehicle vh(company,model,number);

		               if(obj.getMobile()==mobile)
		                {
		                    obj.setVehicleList(vh);
		                }
		                i++;
		            }
		            fpVehicle.close();
				}
				cs.push_back(obj);
			}
			fp.close();
}


void Customer::setAddress(const string& address)
{
	this->address = address;
}

void Customer::setMobile(const string& mobile)
{
	this->mobile = mobile;
}


void Customer::setName(const string& name)
{
	this->name = name;
}

int Customer::getNoOfVehicles()
{
	return this->vehicleList.size();
}


void Customer::setVehicleList(Vehicle v1)
{
	this->vehicleList.push_back(v1);

}


void Customer::newVehicle()
{
	Vehicle v;
	cin>>v;
	this->vehicleList.push_back(v);
	/*for(int i=0;i<this->vehicleList.size();i++)
	cout<<this->vehicleList[i];*/
}


void Customer::saveCustomer(vector <Customer> &cs)
{


	ofstream fp, fpvehicle;
	unsigned int i,j;
	fp.open("Customer.csv");
	fpvehicle.open("Vehicle.csv");
	if(!fp)
	{
		perror("Failed to open Customer File ");
		return;
	}
	if(!fpvehicle)
		{
			perror("Failed to open Vehicle File ");
			return;
		}
	for( i=0;i<cs.size();i++)
	{
		fp<<cs[i].address<<","<<cs[i].mobile<<","<<cs[i].name<<endl;

		vector<Vehicle> temp=cs[i].getVehicleList();
		for(j=0;j<temp.size();j++)
			{
				fpvehicle<<temp[j].getCompany()<<","<<temp[j].getModel()<<","<<temp[j].getNumber()<<","<<cs[i].getMobile()<<endl;
			}
	}
	fpvehicle.close();
	fp.close();
}

void Customer::printRecord(vector<Customer>&cs)
{
	cout<<endl<<"	--------------Registered Customers in Record--------------- "<<endl<<endl;
	int j=1;
	for(unsigned i=0;i<cs.size();i++)
	{
		cout<<"		"<<j<<") "<<cs[i].name<<"		"<<cs[i].mobile<<"		"<<cs[i].address<<endl<<endl;
		++j;
	}
}

Customer::~Customer()
{

}


