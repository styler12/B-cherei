#pragma once
#ifndef STRUCTURE
#define STRUCTURE
#include <string>
using namespace std;

class Loan {
	Medium * medium;
	Date loandate;
	Date expiration;
};

class Address {
	string street;
	string housnr;
	string ziplock;
	string town;
};

class Date {
	short day;
	short month;
	short year;
};

class Person {
	string name;
	Date birthday;
	Address address;
	string id;
};

class Customer : public Person {
	int status;
	Loan * loanlist[];
};

class Employee : public Person {
};
#endif