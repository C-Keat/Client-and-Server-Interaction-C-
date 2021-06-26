#pragma once

#include <exception>
using namespace std;

class AcceptConnectionException: public exception
{
public:

	virtual const char* what() const throw() {
		return  "Accepting connection failed ";
	}

};

