#include "include/error.h"
#include "include/first.h"
#include "include/template.h"
#include "unistd.h"
#include "utmp.h"
#include "fcntl.h"
#include "pwd.h"
#include <map>
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>     /* atoi */



class Car{
	public:
	int x;
  	Car(){x = 0;}
	Car(int x){
		this->x = x;
	}
};

class Foo
{
    private:
	Car item;
    public:
        Foo(){}
        Foo(Car n){
		this->item = n;
	}
    	Car& top() {
		cout << "non const ..." << endl;
		return this->item; 
	}
    	const Car& top() const { 
		cout << "const ..." << endl;
		return this->item; 
	}
};

int fibonacci(int n){
	if (n < 2){
		return n;
	}
	return fibonacci(n - 1) + fibonacci(n - 2);
} 

void printFibonacci(int n){
    static long int first=0,second=1,sum;
    if(n>0){
         sum = first + second;
         first = second;
         second = sum;
         cout << ", " << sum;
         printFibonacci(n-1);
    }
}

class Monitor
{
    static int count;
public:
    void print() { cout << "incident function has been called " << count << " times" << endl; }
    void incident() { cout << "function incident called" << endl; count++; }
};

int Monitor::count = 0;

void callMonitor()
{
    static Monitor fooMonitor;
    fooMonitor.incident();
    fooMonitor.print();
}

class Base {};
class Derive : public Base {};
class Other {};

int main(int argc, char* args[])
{
Car nc1(10);
Car nc2(20);

Foo f1(nc1);
const Foo f2(nc2);

Car c1 = f1.top();
Car c2 = f2.top();
cout << c1.x << endl;
cout << c2.x << endl;

c1.x = 15;


f1.top().x = 19;
//f2.top().x = 29;

int n = 3;
if(argc == 2){
	n = atoi(args[1]); 
}
//cout << "fibonacci of " << n  << " is " << fibonacci(n) << endl;
cout << "0, 1";
printFibonacci(n);
cout << endl;

callMonitor();

Base base;
Derive der;
Base ap = &der;
    Derive* b1 = dynamic_cast<Derive*> (&base);  // NULL, because 'a' is not a 'B'
    Derive* b2 = dynamic_cast<Berive*> (ap);  // 'b'
    Other* o = dynamic_cast<Other*> (ap);   // NULL.

    A& ar = dynamic_cast<A&> (*ap); // Ok.
    B& br = dynamic_cast<B&> (*ap); // Ok.
    C& cr = dynamic_cast<C&> (*ap); // std::bad_cast

//c2.x = 25;
/*
string msg = "Any message...";
response_box db(msg, "Continue", "Cancel", "Retry");
cout << "Response is " << db.getresponse() << endl;
*/

//if(argc == 2) cout << "Hello Sonai...." << args[1] <<  endl;


/*
#forDebug("To test debug only");
{
	MyClass a(10);
	a.~MyClass();	
}
{
	templateClass<int> obj;
	obj.display();
}
*/
/*
{
	BaseClass bArr[5];
	BaseClass b;
	b.displayBase(bArr,5);
	SomeFunc(bArr,5);
	DeriveClass dArr[5];
	DeriveClass d;
	d.displayDerive(dArr,5);
	SomeFunc(dArr);
}
*/
/*
{
	Empty e1, e2;
	cout << "&e1-&e2 = " << sizeof(e1) << endl;
	cout << "sizeof(mUnion)=" << sizeof(mUnion) <<  endl;
}
*/
/*
{
//	A *af = new B();
//	af->show1(100.45);
	B bf;
	bf.show1(10);
	bf.show1(10.122);
}
*/
/*
{
	int x = 100;
	int * const cPtr = &x; 
	cout << "cPtr = " << cPtr << "  "  << (*cPtr) << endl;
	//cPtr = cPtr+1;
	*cPtr = 1222;
	cout << "cPtr = " << cPtr << "  "  << (*cPtr) << endl;

	int* iPtr = const_cast<int*>(cPtr);
//	int* iPtr = cPtr;
	cout << "iPtr = " << iPtr << "  "  << (*iPtr) << endl;
	iPtr = iPtr+1;
	cout << "iPtr = " << iPtr << "  "  << (*iPtr) << endl;
}
*/
/*
{
	A *ax = new A();
	B *bx = new B();
	C *cx = new C();
	bx = static_cast<B*>(ax);
	if(bx)
	{
		cout << "it is a safe cast"<< endl;
		bx->display();
	}
	else
	{
		cout << "it is not a safe cast"<< endl;
	}
	delete ax;
	delete bx;
	delete cx;
}
*/
/*
{
	Derive *d = new Derive();
	Base1 *b1 = d;
	b1->tellMe();
	//b1->tellYou();
	b1->show();

	Base2 *b2 = d;
	//b2->tellMe();
	b2->tellYou();
	b2->show();
	delete b1;
	delete b2;
}
*/
/*
{	
		firstClass f1;	
		cout << f1;	
		//firstClass f2(11,22,"2222222");	
		//f1.tellUs(f2);
}
*/

/*
	unsigned int ij;

	cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
{
	vector<int> vInt;
	vInt.push_back(12);
	vInt.push_back(15);
	vInt.push_back(10);
	vInt.push_back(1);
	vInt.push_back(16);
	vInt.push_back(42);
	vInt.push_back(12);
	vInt.push_back(34);
	vInt.push_back(112);
	vInt.push_back(52);	
	cout << "given values are  = [" ;
	for(ij = 0; ij < vInt.size()-1; ij++)
	{
		cout << vInt[ij] << ", ";
	}
	cout << vInt[ij] << "]" << endl;
	insertSearch(vInt);
	cout << "sorted values are = [" ;
	for(ij = 0; ij < vInt.size()-1; ij++)
	{
		cout << vInt[ij] << ", ";
	}
	cout << vInt[ij] << "]" << endl;
}
	cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
*/
/*
{
	int k = 0;
	int* xx = getArray(10);
	cout << "xx = [" ;
	for(k = 0; k < 9; k++) cout << *(xx+k) << ", "; 
	cout << *(xx+k) << "]" << endl;
	delete [] xx;

 	vector<int *> xy = getVectorArray(10); 
	cout << "xy = [" ;
	for(k = 0; k < 9; k++) 
	{
		cout << *xy[k] << ", "; 
		delete xy[k];
	}
	cout << *xy[k] << "]" << endl;
	delete xy[k];
}
*/
//cout << Common::STARTING << " ## " << Common::max(100,200) << endl;
/*{
	B b;
	A* a = &b; 
	a->show();
	a->display();
	A aa;
	tellMe(aa);
	delete a;
}
*/
/*
{
	vector<firstClass*> vfc;
	for(int i = 0; i < 10; i++)
	{ 
		firstClass *fc=new firstClass((10+i),(30+i),"tkdinda");
		vfc.push_back(fc);
	}
	for(unsigned int j = 0; j < vfc.size(); j++)
	{
		cout << *vfc[j];
		delete vfc[j];
	}
}
*/
/*
cout << "----------------------------------------------"<< endl;
{
	firstClass fc1(100,300, "Rushdeep Dinda");
	cout << fc1;
	try
	{
		fc1.division(20);
		fc1.division(0);
	}
	catch(Error &err)
	{
		cout << err; 
	}
	catch(string &msg)
	{
		cout << msg << endl;
	}
}
*/
/*
{
	int ia = 10;
	int ja = 30;
	int &ptr = ia;
	cout << ia << " # " << ptr << endl;
	ptr += ja;
	cout << ja << " # " << ptr  << endl;
}
*/
/*
{
	cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
	char* message = (char*)malloc(100*sizeof(char));
//	message = "Hello Sonai...";
	forDebug(message);
	cout << "Msg : " << message << endl;
	free(message);
	cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
}
*/
//	cout << Common::END << endl;
/*
{
	map<string,int> ami;
	ami["x1"] = 10;
	ami["x2"] = 20;
	ami["x3"] = 30;
	ami["x4"] = 40;

	cout <<  ami["x1"] << endl;
	cout <<  ami["x2"] << endl;
	cout <<  ami["x3"] << endl;
	cout <<  ami["x4"] << endl;
}
*/

	return 0;
}
