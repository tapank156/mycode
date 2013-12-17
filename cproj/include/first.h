#ifndef _FIRST_
#define _FIRST_

#include "util.h" 
#include <vector>
#include <memory>
//static int gVal = 102030;
class firstClass
{
	int *xyz;
	int m_x;
	int m_y;
	string name;
	int add();
public:
	static int sInt;
	firstClass();
	firstClass(firstClass &fc);
	firstClass(int x, int y, string name);
	friend void operator <<(ostream & dout, firstClass & fc);
	void division(int n);
	~firstClass();
};

class A
{
	int x;
public:
	A():x(20){ cout << "A()"<< endl;}
	virtual ~A(){cout << "~A()"<< endl;}
	virtual void show(){cout << "A::show() "<< x << endl;}
	void show1(int m){cout << "A::show1(m) "<< m << endl;}
	virtual void display(){cout << "A::display() "<< x << endl;}
	void tellUs(A a){a.show(); cout << sizeof(a) << "  %%  "  << endl;}
	void forClassA(){ cout << "in class A()"<< endl;}
//	friend void tellMe(A& a);
	
};

class B : public A
{
	int y;
public:
	void forClassA(){ cout << "in class B()"<< endl;}
	B():y(10){cout << "B()"<< endl;}
	virtual ~B(){cout << "~B()"<< endl;}
	//using A::show1;
	void show1(float m){cout << "B::show1(m) "<< m << endl;}
	void show(){cout << "B::show() "<< y <<  endl;}
	virtual void display(){cout << "B::dispaly() "<< y <<  endl;}
};

class C : public B
{
	int z;
public:
	C():z(40){cout << "C()"<< endl;}
	virtual ~C(){cout << "~C()"<< endl;}
	void show(){cout << "C::show() "<< z <<  endl;}
	virtual void display(){cout << "C::dispaly() "<< z <<  endl;}
};

class Base1
{
	int x;
public:
	Base1():x(10){cout << "Base1()" << endl;}
	virtual ~Base1(){cout << "~Base1()" << endl;}
	void show(){cout << "Base1::show() " << x <<  endl;}
	virtual void tellMe(){cout << "Base1::tellMe() " << x <<  endl;}
};
class Base2
{
	int y;
public:
	Base2():y(20){cout << "Base2()" << endl;}
	virtual ~Base2(){cout << "~Base2()" << endl;}
	void show(){cout << "Base2::show() " << y <<  endl;}
	virtual void tellYou(){cout << "Base2::tellYou() " << y <<  endl;}
};

class Derive : public Base1, virtual public Base2
{
	int z;
public:
	Derive():z(30){cout << "Derive()" << endl;}
	virtual ~Derive(){cout << "~Derive()" << endl;}
	void show(){cout << "Derive::show() " << z <<  endl;}
	virtual void tellMe(){cout << "Derive::tellMe() " << z <<  endl;}
	virtual void tellYou(){cout << "Derive::tellYou() " << z <<  endl;}
};


class BaseClass
{
public:
	int bval;
	BaseClass();
	void displayBase(BaseClass*, int);
};


class DeriveClass : public BaseClass
{
public:
	int dval;
	DeriveClass();
	void displayDerive(DeriveClass*, int);
};



class MyClass
{
	int* val;
public:
	MyClass(int n);
	~MyClass();
};

#endif
