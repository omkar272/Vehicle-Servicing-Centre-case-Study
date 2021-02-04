/*
 * Maintainance.h
 *
 *  Created on: 20-Aug-2020
 *      Author: sunbeam
 */

#ifndef MAINTAINANCE_H_
#define MAINTAINANCE_H_
#include<list>
#include"Part.h"
#include"Service.h"
#include"Exception.h"
#include <fstream>
#include <sstream>
namespace kd3 {

class Maintainance:public Service {
	double labourCharges;
	list<Part> partList;
public:
	Maintainance();
	Maintainance(Part &p);
	void display();
	void addPart(const Part &newPart);
	Part checkPart(list<Part>&temppartlist,int num)throw(Exception);
	double getLabourCharges() const;
	void input();
	void setLabourCharges(double labourCharges);
	const list<Part>& getPartList() const;
	double price();
	void setPartList(const list<Part>& partList);
	void loadPartDetail(list<Part> &temppartlist);

	virtual ~Maintainance();
};

} /* namespace kd3 */

#endif /* MAINTAINANCE_H_ */
