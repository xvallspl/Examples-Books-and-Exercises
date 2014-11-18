/*Imagine you have a call center with three levels of employees: fresher, technical lead
(TL), product manager (PM). There can be multiple employees, but only one TL or PM.
An incoming telephone call must be allocated to a fresher who is free. If a fresher
can’t handle the call, he or she must escalate the call to technical lead. If the TL is
 not free or not able to handle it, then the call should be escalated to PM. Design the
classes and data structures for this problem. Implement a method getCallHandler().*/
#include <iostream>
#include <stdlib.h>
using namespace std;

class Call{
public:
	Call(int p): priority(p){}
	int priority;
	void reply(){
		cout<<"call replied!"<<endl;
	}
};


class Employee{
public:
	Employee(Employee* superior, int l): boss(superior), level(l){}
	void getCallHandler(Call incoming){
		if(!canHandle(incoming)){
			getBoss(incoming);
		}else{
			cout<<"Employee of rank "<<level<<" replying call of priority "<<incoming.priority<<endl;
			incoming.reply();
		}
	}
	void receiveCall(){
		Call incomingCall = Call((rand()%3));
		getCallHandler(incomingCall);
	}

	bool canHandle(Call incoming){
		return(incoming.priority<=level);
	}

	void getBoss(Call incoming){
		boss->getCallHandler(incoming);
	}
private:
	int level;
	Employee* boss;
};


class Fresher:public Employee{
public:
	Fresher(Employee* superior, int level):Employee(superior, level){}
};

class TL:public Employee{
public:
	TL(Employee* superior, int level): Employee(superior, level){}
};

class PM:public Employee{
public:
	PM(Employee* superior, int level):Employee(superior, level){}
};

int main(){
	return 0;
}