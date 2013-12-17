#include "../include/template.h"

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
