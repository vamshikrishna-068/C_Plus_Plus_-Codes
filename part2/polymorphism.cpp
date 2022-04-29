#include <bits/stdc++.h>
using namespace std;
// function overloading
class busi{
public:
	void func(){
		cout<<"Im a function with no arguments"<<endl;
	}
	void func(int x){
		cout<<"Im a function with int argument"<<endl;
	}
	void func(double x){
		cout<<"Im a function with float argument"<<endl;
	}
};
// operator overloading
class Complex{
private:
	int real,imag;
public:
	Complex(int r=0, int i=0){
		real=r;
		imag=i;
		// cout<<real<<" "<<imag<<endl;
	}
	Complex operator + (Complex const &obj){
		Complex a;
		// cout<<real<<" "<<imag<<endl;
		// cout<<obj.real<<" "<<obj.imag<<endl;
		a.imag=imag+obj.imag;
		a.real=real+obj.real;
		// cout<<a.real<<endl;
		return a;
	}
	void display(){
		cout<<real<<" + i"<<imag<<endl;
	}
};
// Run time
class base{
public:
	virtual void fun(){
		cout<<"this is base func"<<endl;
	}
	void print(){
		cout<<"this is BASE print"<<endl;
	}

};
class derived: public base{
public:
	void fun(){
		cout<<"this is DERIVED func"<<endl;
	}
	void print(){
		cout<<"this is derived print"<<endl;
	}
	void b(){
		cout<<"yoo"<<endl;
	}
};
int main(){
//	FUNCTION OVERLOADING
	// busi obj;
	// obj.func();
	// obj.func(2);
	// obj.func(1.2);
//	OPERATIONAL OVERLOADING
	// Complex c1(12,6);
	// Complex c2(10,2);
	// Complex c4(1,1);
	// Complex c3=c1+c2+c4;
	// c3.display();
	base *baseptr;
	derived d;
	baseptr=&d;
	baseptr -> fun();
	baseptr -> print();
	// baseptr -> b();
	return 0;
}