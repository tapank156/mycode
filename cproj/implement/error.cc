#include "../include/error.h"
Error::Error()
{
	errLevel = "Low";
	errMsg = "Simple message ...";
	cout << "Error("<< errMsg <<")" << endl;
}
Error::Error(string msg)
{
	errLevel = "Normal";
	errMsg = msg;
	cout << "Error("<< errMsg <<")" << endl;
}
Error::Error(string level, string msg)
{
	errLevel = level;
	errMsg = msg;
	cout << "Error("<< errMsg <<")" << endl;
}

Error::~Error()
{
	cout << "~Error("<< errMsg <<")" << endl;
}

void  operator << (ostream & dout, Error & err)
{
	dout <<"------------------------------------------------------"<<endl;
	dout << err.errLevel << " : " << err.errMsg << endl;
	dout <<"------------------------------------------------------"<<endl;
//	return dout;
}
