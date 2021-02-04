/*

 * Service.cpp
 *
 *  Created on: 18-Aug-2020
 *      Author: sunbeam
*/



#include"../include/Service.h"

using namespace kd3;
Service::Service() {
	this->desc = " ";
}
Service::Service(const string &desc) {
	this->desc = desc;
}
void Service::display() {
	cout<<"Description 	:  "<<this->desc<<endl;
}
void Service::input() {
	cout<<"Description : ";
	cin>>this->desc;
}

 Service ::~Service(){

 }
