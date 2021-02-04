/*
 * Bill.h
 *
 *  Created on: 18-Aug-2020
 *      Author: sunbeam
 */
#include"ServiceRequest.h"
#include<list>

#ifndef BILL_H_
#define BILL_H_
namespace kd3
{
class Bill {
private:
	double amount;
	double paid_Amount;
	ServiceRequest* servicerequest;
public:
	Bill();
	Bill(double amount, double paid_amount);
	Bill(ServiceRequest *servicerequest,double amount);
	~Bill();
	double computeAmount();
	double computeTax();
	double computeTotalBill();
	double getAmount() const;
	void setAmount(double amount);
	double getPaidAmount() const;
	void setPaidAmount(double paidAmount);
	void display();

	friend ostream& operator<<(ostream &out, Bill &other)
	{
		cout<<"		"<<other.computeTotalBill()<<endl;
		return out;
	}
};
}
#endif /* BILL_H_ */
