#include "../include/common.h"
#include "../include/first.h"
#include "../include/error.h"
//extern int gVal;
int firstClass::sInt = 1928;
firstClass::firstClass(firstClass &f)
{
	xyz = f.xyz;
	name = f.name;
	m_x = f.m_x;
	m_y = f.m_y;
	cout << "firstClass(firstClass&)" << endl;
}

firstClass::firstClass() 
{

	xyz = new int(100);
	name = "Shilpi Dinda";
	m_x = 100;
	m_y = 200;
	cout << "firstClass()" << endl;
}

firstClass::firstClass(int x, int y, string nm)
{
	xyz = new int(x);
	name = nm;
	m_x = x;
	m_y = y;
	cout << "firstClass(" << m_x << ", " << m_y << ", " << name << ")" << endl;
}

void  operator <<(ostream & dout, firstClass & fc)
{
	dout << "Name is "<< fc. name << endl;
	dout << "Sum of " << fc.m_x << " and " <<  fc.m_y << " is " << fc.add() << endl;
//	return dout;
}

void firstClass::division(int n)
{
	if(n == 0) throw Error("Integer devided by zero ...");
	cout << "Division value is " << ((m_x + m_y)/n) << endl;
}

int firstClass::add()
{
	return Common::add(m_x, m_y);
}
	
firstClass::~firstClass()
{
	delete xyz;
	cout << "~firstClass(" << m_x << ", " << m_y << ", " << name << ")" << endl;
}

BaseClass::BaseClass()
{
	bval = 1;
}

void BaseClass::displayBase(BaseClass* arr, int size)
{
	for(int i = 0; i < size; i++, arr++) 
	{
		cout << "Base arr[" << i << "] = " <<  arr->bval << " at the address " << arr << endl;
	}

}
void DeriveClass::displayDerive(DeriveClass* arr, int size)
{
	for(int i = 0; i < size; i++, arr++) 
	{
		cout << "Derive arr[" << i << "] = " <<  arr->bval << " at the address " << arr << endl;
	}

}
DeriveClass::DeriveClass()
{
	dval = 2;
}
MyClass::MyClass(int n)
{
	val = new int[n];
	for(int i =0 ;i < n ; i++) val[i] = i*10;
	cout << "MyClass::MyClass(int)" << endl;
}

MyClass::~MyClass()
{
	cout << "MyClass::~MyClass()" << endl;
	delete [] val;
}


/*
void tellMe(A& a)
{
	A aa;
	cout << "tellMe()->friend "<< aa.x <<  endl;
}

*/



