/*
 * main.cpp
 *
 *  Created on: 17-Aug-2020
 *      Author: Omkar Gaikwad
 */

#include<iostream>
using namespace std;
#include <iomanip>
#include<vector>
#include<map>
#include <fstream>
#include <sstream>
#include"../include/Customer.h"
#include"../include/Vehicle.h"
#include"../include/ServiceStation.h"
#include"../include/Maintainance.h"
#include"../include/Part.h"
#include"../include/Oil.h"
#include"../include/Service.h"
#include"../include/ServiceRequest.h"

void printbill();
void printline();
void printline1();
void printline2();

 using namespace kd3;

 int mainMenu()throw(Exception)
 {

	 int choice;
	 cout<<endl<<"		0.Exit"<<endl;
	 cout<<"		1.Register New Customer"<<endl;
	 cout<<"		2.Servicing Request"<<endl;
	 cout<<"		3.Today Business"<<endl;
	 cout<<"		Enter your Choice : ";
	 if(cin>>choice)
		 return choice;
	 else
		 throw Exception("Entered Choice is in-correct!!!");

 }

 int serviceMenu()throw(Exception)
  {
 	 int choice;
 	 cout<<endl<<"		0.Exit"<<endl;
 	 cout<<"		1.New Vehicle"<<endl;
 	 cout<<"		2.Servicing Existing vehicle (If exist): "<<endl;
 	 cout<<"		Enter your Choice : ";
 	 if(cin>>choice)
 		 return choice;
 	 else
 		 throw Exception("Entered Choice is in-correct!!!");
  }

 int serviceMenu2()throw(Exception)
   {
  	 int choice;
  	 cout<<endl<<"		0.Exit"<<endl;
  	 cout<<"		1.Oil change"<<endl;
  	 cout<<"		2.Maintainanace / Full Servicing "<<endl;
  	 cout<<"		Enter your Choice : ";
  	 if(cin>>choice)
  		 return choice;
  	 else
  		 throw Exception("Entered Choice is in-correct!!!");
   }

 int menuListPart()throw (Exception)
	{
	 int choice;
	 cout<<endl<<"		0.Exit"<<endl;
	 cout<<"		1.Enter Part"<<endl;
	 cout<<"		Enter Your Choice : ";
	 if(cin>>choice)
	  		 return choice;
	  	 else
	  		 throw Exception("Entered Choice is in-correct!!!");
	 }



int main()
{
	int ch1,ch2,ch3,ch4;
	vector<string> temp;
	Customer customer;
	map<string, double> billing;
	vector<Customer> cs;
	list<Part> temppartlist;
	customer.loadCustomer(cs);
	Customer *customerPtr=NULL;
	Service *ServicePtr =NULL;
	list<Service*> ServiceList;
	list<Part> partlist;

	ServiceStation &Servicestation=ServiceStation::getInstance();//singleton obj
	try{
	while((ch1=mainMenu())!=0)
	{ cout<<endl;
		switch(ch1)
		{
			case 0:
				break;
			case 1://new customer
				{

					Customer c1;
					c1.input();
					cs.push_back(c1);
					customer.saveCustomer(cs);
					cs.clear();
					customer.loadCustomer(cs);
					printline();
					customer.printRecord(cs);
					printline();
				}//new customer case
				break;
		case 2: //servicing request
		{
				printline();
				string mobile;
				customer.printRecord(cs);
				printline();
				cout<<endl<<"		Enter Mobile Number Of Customer : ";
				cin>>mobile;
				Servicestation.loadCustomerDetail();
				customerPtr=Servicestation.findCustomer(mobile);
				cs.clear();
				customer.loadCustomer(cs);
				//printline();
				cout<<endl<<"@"<<customerPtr->getName()<<"  Mobile : "<<customerPtr->getMobile()<<endl<<endl;
				customerPtr->displayVehicles();
				printline2();
				while((ch2=serviceMenu())!=0)
				{
					switch(ch2)
					{
						case 0:
							break;
						case 1://new vehicle
							{
								for(unsigned i=0;i<cs.size();i++)
									{
										if(cs[i].getMobile()==customerPtr->getMobile())
											{
												cs[i].newVehicle();
												cout<<cs[i];
												customer.saveCustomer(cs);
												cs.clear();
											}
									}
							}//case1
							break;
						case 2://select existing vehicle
							{
								Servicestation.loadCustomerDetail();
								customerPtr=Servicestation.findCustomer(mobile);
								ServiceRequest Servicerequest;
								Maintainance maintainance;
								vector<Vehicle> v1;
								if(customerPtr->getNoOfVehicles())
									{
										Servicerequest.setCustomerName(customerPtr->getName());
										v1=customerPtr->getVehicleList();

										cout<<endl<<"		Registered Vehicles - "<<endl;
										for(unsigned i=0;i<v1.size();i++)
											{
												cout<<"		"<<i+1<<") "<<v1[i].getModel()<<"-	"<<v1[i].getNumber()<<endl;
											}

										double model;
										cout<<endl<<"		Enter vehicle Number for servicing : ";
										cin>>model;

										//selection of vehicle logic keep on hold temporary
										while( (ch3=serviceMenu2())!=0)
											{
												switch(ch3)
													{
														case 0:
															break;
														case 1://oil change
															ServicePtr=(Service*) new Oil();
															ServicePtr->input();
															Servicerequest.setServiceList(ServicePtr);
															break;
														case 2://maintainance
															while((ch4=menuListPart())!=0)
																{
																	switch(ch4)
																		{
																			case 1://add part;
																				{
																					int num;
																					maintainance.loadPartDetail(temppartlist);
																					list<Part>::iterator itr;
																					itr=temppartlist.begin();
																					cout<<endl<<"		"<<"Part No. "<<"		"<<"Rate"<<endl;
																					printline2();
																					while(itr!=temppartlist.end())
																					{
																						(*itr).display();
																						++itr;
																					}
																					cout<<endl<<"		Choose Part Number : ";
																					cin>>num;
																					Part p;
																					p=maintainance.checkPart(temppartlist,num);

																					//maintainance.getPartList();
																					ServicePtr=(Service*) new Maintainance(p);
																					Servicerequest.setServiceList(ServicePtr);
																					maintainance.addPart(p);

																				}
																				break;
																			default:
																				cout<<"Enter Only Right Choice"<<endl;
																		}
																}//while menulist part
															ServicePtr->input();
															cout<<endl<<"		-------------------Full Servicing Done..!!!--------------------- "<<endl<<endl;
															break;
														default:
															cout<<"Enter Only Right Choice"<<endl;
													}//switch

											}//while serviceMenu2()

									}//if
								else
									cout<<"		No any Vehicle Exist for selecting Customer"<<endl;

								partlist=maintainance.getPartList();
								double price=0;
								list<Part>::iterator itr;
								itr=partlist.begin();

									while(itr!=partlist.end())
									{
										price+=(*itr).getRate();
										++itr;
									}

								Bill bill(&Servicerequest,price);
								bill.computeAmount();

								 printbill();
								bill.display();
								printline1();
								customerPtr->payBill(bill);
								Servicestation.setBillList(bill);
								cout<<"		Balance Amount : "<<bill.computeTotalBill()-bill.getPaidAmount()<<endl<<endl;
								cout<<"		-------------------Thank You!!!-------------------"<<endl;
								billing[mobile]=bill.computeTotalBill();
								Servicestation.saveBill(mobile);
							}//case 2 maintainance
						break;
					default:
						cout<<"Enter Only Right Choice !!!!"<<endl;
					}//servicing switch
				}//servicing menu while

			}
				break;

		case 3: //today business
			{
				printline();
				cout<<endl;
				double business=0;
				Customer *customerptr1;
				business=Servicestation.computeCash();
				map<string, double> ::iterator it;
				it= billing.begin();
				while(it!=billing.end())
					{
						customerptr1=Servicestation.findCustomer(it->first);
						cout<<customerptr1->getName();
						cout<<"		"<<it->first<<"		"<<it->second<<"/Rs"<<endl;
						++it;
					}
				printline2();
				cout<<endl<<"		Today Total Business Cash : "<<business<<" Rs/-"<<endl;
				printline();
			}
			break;

		default:
			cout<<"Enter Correct choice...!!!"<<endl;
		}//main switch
	}//outer while mainmenu
	}//try block
	catch(Exception &ex)
	{
		cout<<endl<<ex.getMassage()<<endl;
	}
	return 0;
}























void printline()
{
	cout<<"======================================================================="<<endl;

}


void printbill()
{
	cout<<endl<<"	========================================================="<<endl;
	cout <<"	 ||	 >--Hero-Honda Servicing Center--<	||"<<endl;
	cout<<"	========================================================="<<endl;
}


void printline1()
{
	cout<<"	========================================================="<<endl;
}

void printline2()
{
	cout<<"	--------------------------------------------------------"<<endl;
}
