/*

 * Oil.cpp
 *
 *  Created on: 18-Aug-2020
 *      Author: sunbeam
*/

using namespace std;
#include"../include/Oil.h"
using namespace kd3;
Oil::Oil() {
	this->cost = 0;
}
Oil::Oil( double cost) {
	this->cost=cost;
}
void Oil::display() {
	cout<<"		Oil ";
	Service::display();
cout<<"		Oil Prize 	 	:  "<<this->cost<<endl;
}
void Oil::input() {
	cout<<endl<<"		Oil ";
	Service::input();
	cout << "		Price	:	";
	cin >> this->cost;
}
double Oil::price() {

	return this->cost;
}

Oil::~Oil(){

}

