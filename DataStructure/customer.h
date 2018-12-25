#include <iostream>
using namespace std;
#include <string>
class Customer
{
public:
	Customer(string name="", int age=0);
	void printInfo()const;
private:
	string m_strName;
	int m_iAge;
};




