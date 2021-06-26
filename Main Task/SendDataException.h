#pragma once


#include <exception>

using namespace std;

class SendDataException:public exception
{

public:

	virtual const char* what() const throw() {
		return "Data unable to send";
	}

};

