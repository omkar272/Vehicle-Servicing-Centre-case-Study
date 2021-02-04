/*
 * Service.h
 *
 *  Created on: 20-Aug-2020
 *      Author: sunbeam
 */
#ifndef INCLUDE_SERVICES_H_
#define INCLUDE_SERVICES_H_
#include<cstring>
#include<iostream>
using namespace std;
namespace kd3{
class Service {
	string desc;
public:
	Service();
	Service(const string &desc);
	virtual void display();
	virtual void input();
	virtual double price()=0;
	const string& getDesc() const
	{
		return desc;
	}
	void setDesc(const string &desc) {
		this->desc = desc;
	}
virtual ~Service();

};
}
#endif /* INCLUDE_SERVICES_H_ */
