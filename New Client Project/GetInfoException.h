#pragma once

#include <exception>
using namespace std;

class GetInfoException :public exception
{
public:

	virtual const char* what() const throw() {
		return "getting name info failed";
	}

};

