#include "customer.h"

#include <iostream>
using namespace std;

Customer::Customer(string name, int age) {
	m_strName = name;
	m_iAge = age;
}

void Customer::printInfo()const {
	cout << "����:"<< m_strName << endl;
	cout << "����" << m_iAge << endl;
	cout << endl;
}