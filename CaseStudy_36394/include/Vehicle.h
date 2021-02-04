/*
 * Vehicle.h
 *
 *  Created on: 17-Aug-2020
 *      Author: sunbeam
 */

#ifndef VEHICLE_H_
#define VEHICLE_H_
#include<iostream>
using namespace std;
#include <iomanip>
namespace kd3 {
class Vehicle
{
	private:
		string company;
		string model;
		string number;

	public:
		Vehicle();
		Vehicle(string company,string model,string number );
		~Vehicle();
		const string& getCompany() const;
		void setCompany(const string& company);
		const string& getModel() const;
		void setModel(const string& model);
		const string& getNumber() const;
		void setNumber(const string& number);
		void printVehicle();

		friend istream& operator>>(istream &in,Vehicle &other)
				{
						cin.ignore();
					cout<<endl<<"		Enter Company Name Of Vehicle : ";
					getline (in,other.company);
					cout<<"		Enter Model : ";
					getline (in,other.model);
					cout<<"		Enter Vehicle Number : ";
					getline (in,other.number);
					return in;
				}

		friend ostream& operator<<(ostream &out,const Vehicle &other)
				{
					out<<setw(10)<<other.company<<setw(10)<<other.model<<setw(10)<<other.number<<endl;
					return out;
				}

	void print()
			{
				cout<<this->company<<setw(10)<<this->model<<setw(10)<<this->number<<endl;
			}


};
//using namespace kd3;


} /* namespace kd3 */

#endif /* VEHICLE_H_ */
