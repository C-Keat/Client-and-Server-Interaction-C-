#pragma once

#include <exception>
using namespace std;

class ConnectToServerException:public exception
{
public:

	virtual const char* what() const throw() {
		return "Failed to connect to the server";
	}

};

