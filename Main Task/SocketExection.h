#pragma once

#include <exception>

using namespace std;

class SocketExection:public exception
{
public:
	
	virtual const char* what() const throw() {
		return "SOCKET ERROR";
	}
};


