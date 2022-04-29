#include <bits/stdc++.h>
using namespace std;
class student{
	string name;
	public:
	int age;
	bool gender;
	void setname(string s){
		name=s;
	}
	// default constructor
	student(){
		cout<<"default constructor"<<endl;
	} // default constructor
	student(string s,int a,int g){
		name=s;
		age=a;
		gender=g;
	}// parameterised constructor 
	student(student &a){
		cout<<"copy constructor"<<endl;
		name=a.name;
		age=a.age;
		gender=a.gender;
	} // copy constructor
	~student(){
		cout<<"destructor"<<endl;
	}
	void getname(){
		cout<<name<<endl;
		// cout<<age<<endl;
		// cout<<gender<<endl;
	}
	void print(){
		cout<<"name=";
		cout<<name<<endl;
		cout<<"age=";
		cout<<age<<endl;
		cout<<"gender=";
		cout<<gender<<endl;
	}
	bool operator==(student &d){
		if(name==d.name && age==d.age && gender==d.gender)
			return true;
		else
			return false;
	}
};
int main(){
	// method-1
	// student a[3];
	// for(int i=0;i<3;i++){
	// 	string s;
	// 	cin>>s;
	// 	a[i].setname(s);
	// 	cin>>a[i].age;
	// 	cin>>a[i].gender;
	// }
	// for(int i=0;i<3;i++){
	// 	a[i].print();
	// }
	student a("busi",21,0);
	// a.getname();
	// a.print();
	student b;
	student c=a;
	if(c==a){
		cout<<"same"<<endl;
	}
	else
		cout<<"not same"<<endl;
	return 0;
}