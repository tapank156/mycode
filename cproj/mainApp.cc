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

typedef char* p_char;

void forDebug(char* message)
{
	char *user, *ttydata;
	struct passwd *pwd;
	int uid; 
	static int fd;
	FILE *fp;
	struct utmp *utmp;
//	ttydata = new char[50];
	uid = getuid();
	pwd = getpwuid(uid);
	setutent();
	user = pwd ? pwd->pw_name : p_char("root");
	cout << user << " # " << pwd << endl;
	while((utmp = getutent()) != NULL)
	{
		if(utmp->ut_type != USER_PROCESS || 
			utmp->ut_user[0] == 0 ||
			strcmp(utmp->ut_user, user))
		{
			continue;
		}
		sprintf(ttydata, "/dev/%s", utmp->ut_line);
		cout << ttydata << endl;
		fd = open(ttydata, O_WRONLY | O_NDELAY);
		if((fp = fdopen(fd, "w")) != NULL)
		{
			fputs(message, fp);
			fputs("\n",fp);
			fclose(fp);
		}
		else
		{
			close(fd);
		}
	}
	endutent();
	delete [] ttydata;
}

int* getArray(int n)
{
 	int* x;
	x = new int[n];
	for(int k = 0; k < n; k++) x[k] = (k+2);
	return x;
}

vector<int *> getVectorArray(int n)
{
 	vector<int *> x;
	for(int k = 0; k < n; k++) x.push_back(new int(k+10));
	return x;
}

template< class T >
void insertSearch(vector<T> & a)
{
	unsigned int i,j;
	for(i=1; i < a.size(); i++)
	{
		T tmp = a[i];
		for(j = i; (j>0 && tmp < a[j-1]); j--)
			a[j] = a[j-1];
		a[j] = tmp;
	}
}

class Empty{};

void SomeFunc(BaseClass* arr, int size)
{
	//if(typeid(arr) = BaseClass) cout << "Base" << endl;
	for(int i = 0; i <= size; i++, arr++) 
	{
		cout << "arr[" << i << "] = " <<  arr->bval << " at the address " << arr << endl;
	}
}
void SomeFunc(BaseClass arr[5])
{
	//if(typeid(arr) = BaseClass) cout << "Base" << endl;
	for(int i = 0; i <= 5; i++, arr++) 
	{
		cout << "arr[" << i << "] = " <<  arr->bval << " at the address " << arr << endl;
	}
}

int main(int argc, char* args[])
{
/*
string msg = "Any message...";
response_box db(msg, "Continue", "Cancel", "Retry");
cout << "Response is " << db.getresponse() << endl;
*/

if(argc == 2) cout << "Hello Sonai...." << args[1] <<  endl;

#forDebug("To test debug only");
{
	MyClass a(10);
	a.~MyClass();	
}
/*
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
