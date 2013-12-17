#ifndef _COMMON_
#define _COMMON_

#include "util.h" 
namespace Common
{
	string STARTING = "Start of the program ...";
	string WORNING = "This common worning ...";
	string ERROR = "This is common error ...";
	string END = "End of the program ...";
	int max(int x, int y)
	{
		if(x>y)
			return x;
		else
			return y;
	}
	int add(int x, int y)
	{
		return (x+y);
	}
}
using namespace Common;
#endif
