
#include "../include/ServiceStation.h"
 using namespace kd3;

 ServiceStation::ServiceStation() {}


 ServiceStation::ServiceStation(const string &name)
 {
 	this->name=name;
 }

 ServiceStation::ServiceStation(const ServiceStation &other)
 {
	 this->name=other.name;
	this->billList=other.billList;
	this->custList=other.custList;
 }

 double ServiceStation::computeCash()
 {

	 int i=0;
	 double business=0;
	 list<Bill>::iterator itr;
	 itr= this->billList.begin();
	 while(itr!=this->billList.end())
	 {
		 business+=(*itr).computeTotalBill();
		 ++itr;

	 }
	 return business;
 }


 void ServiceStation::displayCustomer()
 {

	 list<Customer>::iterator trav;
	 trav=(this->custList.begin());
			 while(trav!=this->custList.end())
				{
				 cout<<(*trav);
				 trav++;
				}
 }


 Customer* ServiceStation:: findCustomer(const string number)throw(Exception)
 {
	 list<Customer>::iterator it;
	 it=(this->custList.begin());
	 	 while(it!=this->custList.end())
	 		{
	 			if((*it).getMobile()==number)
	 			{

	 				return&(*it);
	 			}
	 			it++;
	 		}
	 	 throw Exception("Customer Not Found !!!");
 }


 const list<Customer>& ServiceStation::getCustmerList() const
 {
 	return this->custList;
 }

 const list<Bill>& ServiceStation::getBillList() const
 {
 	return billList;
 }

 const string& ServiceStation::getName() const
 {
 	return name;
 }

 void ServiceStation::setBillList(const Bill& billList)
 {
 	this->billList.push_back(billList);

 }


 void ServiceStation::setCustList(const list<Customer>& custList)
 {
 	this->custList = custList;
 }


 void kd3::ServiceStation::setName(const string& name)
 {
 	this->name = name;
 }

 void ServiceStation::newCustomer()
 {
	 Customer c;
	 Vehicle v;
	 c.input();
	cin>>v;//need validation of mobile number
	c.setVehicleList(v);
	 this->custList.push_back(c);
 }


 void ServiceStation::loadCustomerDetail()
 {
	 this->custList.clear();
	 ifstream fp,fpVehicle;
	 	fp.open("Customer.csv");
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
	 				Customer obj(token[0],token[1],token[2]);
	 				{
	 					i=0;
	 					fpVehicle.open("Vehicle.csv");
	 		            if(!fpVehicle)
	 		            {
	 		                perror("failed to open vehicle file");
	 		                return;
	 		            }
	 		            while(getline(fpVehicle, line))
	 		            {

	 		                stringstream str(line);

	 		                string token[4];
	 		                string company,model,number, mobile;
	 		                for(int q=0;q<4;q++)
	 		                {
	 		                	getline(str,token[q],',');

	 		                }
	 		                company=token[0];
	 		                model=token[1];
	 		                number=token[2];
	 		                mobile=token[3];

	 						Vehicle vh(company,model,number);

	 		               if(obj.getMobile()==mobile)
	 		                {
	 		                    obj.setVehicleList(vh);
	 		                }
	 		                i++;
	 		            }

	 		            fpVehicle.close();
	 				}
	 				this->custList.push_back(obj);
	 			}

	 				fp.close();
 }


 void ServiceStation::storeCustomerDetail()
 {
	 ofstream fp, fpvehicle;
	 	unsigned int i,j;
	 	fp.open("Customer.csv");
	 	fpvehicle.open("Vehicle.csv");
	 	if(!fp)
	 	{
	 		perror("Failed to open Customer File ");
	 		return;
	 	}
	 	if(!fpvehicle)
	 		{
	 			perror("Failed to open Vehicle File ");
	 			return;
	 		}
	 	list<Customer>::iterator itr;
	 	itr=this->custList.begin();

	 	while(itr!=this->custList.end())
	 	{
	 		fp<<(*itr).getAddress()<<","
	 				<<(*itr).getMobile()<<","
					<<(*itr).getName()<<endl;
	 		vector<Vehicle> temp=(*itr).getVehicleList();
	 		for(j=0;j<temp.size();j++)
	 			 	{
	 			 		fpvehicle<<temp[j].getCompany()<<","
	 			 				<<temp[j].getModel()<<","
								<<temp[j].getNumber()<<","
								<<(*itr).getMobile()<<endl;
	 			 	}

	 		++itr;
	 	}

	 	fpvehicle.close();
	 	fp.close();
 }



 void ServiceStation::saveBill(string mobile)
 {
 	ofstream fp;
 	unsigned int i,j;
 	fp.open("Bill.csv");
 	if(!fp)
 	{
 		perror("Failed to open Bill File ");
 		return;
 	}

 	list<Bill>::iterator itr;
 		 	itr=this->billList.begin();

 		 	while(itr!=this->billList.end())
 		 	{
 		 		fp<<(*itr).getAmount()<<","
 		 				<<(*itr).getPaidAmount()<<","
 						<<mobile<<endl;
 		 		++itr;
 		 	}

 	fp.close();
 	//cout<<"Billl file save Suceesfully"<<endl;
 }

 void ServiceStation::loadBillDetail(vector<string> &temp)
  {
 	 this->billList.clear();
 	 ifstream fp;
 	 	fp.open("Bill.csv");
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
 	 				string token[2];
 	 				for(i=0;i<2;i++)
 	 				{
 	 					getline(str,token[i],',');
 	 				}
 	 				Bill obj(stod(token[0]),stod(token[1]));
 	 				temp.push_back(token[2]);

 	 				this->billList.push_back(obj);
 	 			}
 	 			// cout<<endl<<"Vehicle File Loaded "<<endl;
 	 			//cout<<"Customer File get Loaded "<<endl;
 	 				fp.close();
  }




   ServiceStation& ServiceStation::getInstance()
 {
 	static ServiceStation s1;
 	return s1;
 }

 ServiceStation::~ServiceStation()
 {
 	// TODO Auto-generated destructor stub
 }


