#pragma once

#include <exception>

using namespace std;

class WSAException :public exception
{

public:

	virtual const char* what() const throw() {
		return "Windsock Dll not found !";
	}
};