#ifndef _TEMPLATE_
#define __TEMPLATE_
#include "util.h" 

template<class T>
class templateClass
{
	T var;
public:
	templateClass();
	templateClass(T v);
	~templateClass();
	void display();
};
template<class T>
templateClass<T>::templateClass()
{
	var = T(12);
	cout << "templateClass::templateClass()" << endl;
}

template<class T>
templateClass<T>::templateClass(T v)
{
	var = v;
	cout << "templateClass::templateClass(T)" << endl;
}

template<class T>
templateClass<T>::~templateClass()
{
	cout << "templateClass::~templateClass()" << endl;
}

template<class T>
void templateClass<T>::display()
{
	cout << "templateClass::display()" << endl;
}

template < class X>
class smart_pointer
{
private:
public:
 	smart_pointer();
	smart_pointer(const X& x);
	X& operator *();
	const X& operator *() const;
	X* operator ->() const;
	smart_pointer(const smart_pointer<X>&);
	const smart_pointer<X>& operator =(const smart_pointer<X>&);
	~smart_pointer();

};
#endif
