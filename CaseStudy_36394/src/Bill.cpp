/*
 * Bill.cpp
 *
 *  Created on: 18-Aug-2020
 *      Author: sunbeam
 */

#include "../include/Bill.h"
using namespace kd3;
Bill::Bill()
{
	this->amount=0;
	this->paid_Amount=0;
	this->servicerequest=NULL;
}
Bill::Bill(double amount, double paid_amount)
{
	this->amount=amount;
	this->paid_Amount=paid_amount;

}
Bill::Bill(ServiceRequest *servicerequest,double amount=0)
{
	this->amount=amount;
	this->paid_Amount=0;
	this->servicerequest=servicerequest;
}

double Bill::computeAmount()
{
	for (Service* service : this->servicerequest->getServiceList())
		{
			this->amount += service->price();
		}
		return amount;
}

void Bill::display()
{
	for (Service* service : this->servicerequest->getServiceList())
			{
				service->display();
			}

	double total,tax;
	tax=this->computeTax();
	cout<<endl<<"		"<<"Amount			: "<<this->amount<<endl;
	cout<<"		"<<"12.6% Tax    		: "<<tax<<endl;
	cout<<"	    ---------------------------------------"<<endl;
	cout<<"		"<<"Total Bill 		: "<<this->computeTotalBill()<<endl;
}
double Bill::computeTax()
{

	return ((12.6*this->amount)/100);
}

double Bill:: computeTotalBill()
{
	return (this->amount+computeTax());
}

double kd3::Bill::getAmount() const
{
	return amount;
}

void kd3::Bill::setAmount(double amount)
{
	this->amount = amount;
}

double kd3::Bill::getPaidAmount() const
{
	return this->paid_Amount;
}

void kd3::Bill::setPaidAmount(double paidAmount)
{
	this->paid_Amount = paidAmount;
}




Bill::~Bill() {}


