#pragma once



#include <exception>

using namespace std;


class ReciveDataException :public exception
{
public:

	virtual const char* what() const throw() {
		return "Data unable to be recived";
	}

};

