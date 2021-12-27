#pragma once
#include <iostream>
#include <exception>
using namespace std;

class Exception : public exception {
private:
	string err;

public:
	Exception(std::string err) : 
		err(err) {}
	const char* what() const noexcept 
	{
		return err.c_str();
	}
};