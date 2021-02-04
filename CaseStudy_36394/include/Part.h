/*
 * Part.h
 *
 *  Created on: 17-Aug-2020
 *      Author: sunbeam
 */

#ifndef PART_H_
#define PART_H_
#include<iostream>
using namespace std;
namespace kd3
{

class Part 
{ 	
	private:
		string desc;
		int partNo;
		double rate;
public:
		Part();
	Part(int partNo,string desc,double rate);
	~Part();
	const string& getDesc() const;
	double getRate() const;
	int getPartNo() const;
	void setPartNo(int partNo);
	void input();
	void display();
	void setDesc(const string& desc);
	void setRate(double rate);
	friend istream& operator>>(istream &in,Part &other)
	{
		cout<<endl<<"Part Description : ";
		in>>other.desc;
		cout<<"Enter Prize : ";
		in>>other.rate;
		return in;
	}

	friend ostream& operator<<(ostream &out,Part &other)
	{
		out<<"		Part Description 	:  "<<other.desc<<endl;
		out<<"		Prize            	:  "<<other.rate<<endl;
		return out;
	}
};

} /* namespace kd3 */

#endif /* PART_H_ */
