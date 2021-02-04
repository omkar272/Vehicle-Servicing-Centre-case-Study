#ifndef INCLUDE_OIL_H_
#define INCLUDE_OIL_H_
#include"../include/Service.h"
namespace kd3{
class Oil:public Service
{
	double cost;
public:
	Oil();
	Oil(double cost);
	virtual void display();
	 void input();
	virtual double price();
	virtual ~Oil();
	double getCost() const {
		return cost;
	}

	void setCost(double cost) {
		this->cost = cost;
	}
	friend istream& operator>>(istream & cin,Oil &other)
			{
				string desc;
				double cost;
				cout<<"Description	:	";
				cin>>desc;
				other.setDesc(desc);
				cout<<"Price	:	";
				cin>>cost;
				other.setCost(cost);
				return cin;
			}
		friend ostream& operator<<(ostream & cout,Oil &other)
			{
				cout<<"Oil description	:	"<<other.getDesc()<<endl;
				cout<<"oil price	:"<<other.getCost()<<endl;
				return cout;
			}
};
}





#endif /* INCLUDE_OIL_H_ */
