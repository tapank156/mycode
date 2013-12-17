#ifndef _ERROR_
#define _ERROR_

#include "util.h"
class Error
{
	string errLevel;
	string errMsg;
public:
	Error();
	~Error();
	Error(string msg);
	Error(string level, string msg);
	friend void operator << (ostream & dout, Error & err); 
};

#endif
