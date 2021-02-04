/*


 * Maintainance.cpp
 *
 *  Created on: 18-Aug-2020
 *      Author: sunbeam
*/

#include "../include/Maintainance.h"

using namespace kd3;

Maintainance::Maintainance() {
	this->labourCharges=0;
}

Maintainance::Maintainance(Part &p) {
	this->partList.push_back(p);
	this->labourCharges=0;
}

double Maintainance::getLabourCharges() const
{
	return labourCharges;
}

void Maintainance::display()
{

	list<Part>::iterator itr;
	itr=this->partList.begin();
	while(itr!=this->partList.end())
	{
		cout<<(*itr);
		++itr;

	}
	if(this->labourCharges!=0)
	cout<<endl<<"		Labour Charges 	 	:  "<<this->labourCharges<<endl;
}

void Maintainance::addPart(const Part &newPart)
{
	this->partList.push_back(newPart);
}

Part Maintainance::checkPart(list<Part>&temppartlist, int num)throw(Exception)
{
	list<Part>::iterator itr;
	itr=temppartlist.begin();

	while(itr!=temppartlist.end())
		{
			if(num==(*itr).getPartNo())
			{
				return (*itr);
			}
			++itr;
		}
	throw Exception ("Entered part number not available ");

}


void Maintainance::input()
{
	cout<<endl<<"Enter Labour Charges     : ";
	cin>>this->labourCharges;
}
void Maintainance::setLabourCharges(double labourCharges)
{
	this->labourCharges = labourCharges;
}

const list<Part>& Maintainance::getPartList() const
{
	return partList;
}

void Maintainance::setPartList(const list<Part>& partList)
{
	this->partList = partList;
}
double Maintainance::price ()
{
	return this->labourCharges;
}


void Maintainance::loadPartDetail(list<Part> &temppartlist)
  {
	temppartlist.clear();
 	 ifstream fp;
 	 	fp.open("Part.csv");
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
 	 				Part obj(stoi(token[0]),(token[1]),stod(token[2]));

 	 				temppartlist.push_back(obj);
 	 			}


 	 				fp.close();
  }

Maintainance::~Maintainance() {}


