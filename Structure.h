#pragma once
#ifndef STRUCTURE
#define STRUCTURE
#include <string>
#include <iostream>
#include <time.h>
#include <fstream>
#include "Parse.h"

using namespace std;


class Loan {
	/*Medium * medium;
	Date loandate;
	Date expiration;*/
};


class Date {
private:
	short day;
	short month;
	short year;
	time_t t;
	tm * ts;
public:
	short getYear() {
		return year;
	}
	short getMonth() {
		return month;
	}
	short getDay() {
		return day;
	}
	void setYear(short year) {
		this->year = year;
	}
	void setMonth(short month) {
		this->month=month;
	}
	void setDay(short day) {
		this->day=day;
	}
	void printDate() {
		cout << "Geburtsdatum: " << day<< ":" << month << ":" << year;
	}

	/*
	* Method to read from XML File
	*/
	virtual void Date::load(ifstream  *file);
	/*
	* set custom Date
	* @day
	* @month
	* @year
	*/
	void setDate(short day, short month, short year) {
		ts->tm_mday=day;
		ts->tm_mon=month;
		ts->tm_year = year;
	}
	/*
	*set actual Date
	*/
	void updateDate() {
		t = time(NULL); //revert time since 1970 in sec
		ts = localtime(&t); // convert time in stuct
		day = ts->tm_mday;
		month =1 + ts->tm_mon;
		year = 1900 + ts->tm_year;
	}
	Date::Date(ifstream *file);
	Date() {
		updateDate();
		//cout << "Die aktuelle Datum beträgt: " << asctime(ts) << endl;
	}
	Date(short day,short month, short year) {
		this->day = day;
		this->month = month;
		this->year = year;
	}
};
class Address {
private:
	string street;
	string housnr;
	string ziplock;
	string town;
public:

	string getStreet() {
		return street;
	}
	string getHouseNr() {
		return housnr;
	}
	string getZiplock() {
		return ziplock;
	}
	string getTown() {
		return town;
	}
	void setStreet(string street) {
		this->street = street;
	}
	void setHouseNr(string housnr) {
		this->housnr = housnr;
	}
	void setZiplock(string ziplock) {
		this->ziplock = ziplock;
	}
	void setTown(string town) {
		this->town = town;
	}
	void setAll(string street, string housnr, string ziplock, string town) {
		this->street = street;
		this->housnr = housnr;
		this->ziplock = ziplock;
		this->town = town;
	}
	void printAddress() {
		cout << street << " " << housnr << endl << ziplock << " " << town;
	}

	/*
	* Method to read from XML File
	*/
	Address() {}
	virtual void Address::load(ifstream  *file);
	Address::Address(ifstream *file);
	Address(string street, string housnr, string ziplock, string town) {
		this->street = street;
		this->housnr = housnr;
		this->ziplock = ziplock;
		this->town = town;
		
	}

};
class Person {
private:
	string name;
	Date birthday;
	string id;
	Address address;
public:
	
	string getName() {
		return name;
	}
	Date getDate() {
		return birthday;
	}
	string getID() {
		return id;
	}
	Address getAddress() {
		return address;
	}
	void setName(string name) {
		this->name = name;
	}
	void setID(string id) {
		this->id = id;
	}
	void printPerson() {
		cout << "ID: " << id << "Name: " << name << endl;
		address.printAddress();
		cout << endl;
		birthday.printDate();
	}
	virtual void Person::load(ifstream  *file);
	~Person() {
		cout << "\nPerson: " << name << " wurde vernichtet" << endl;
	}
	Person(string name, Address address, Date birthday):address(address) {
		this->name = name;
		this->birthday = birthday;
	}
	Person::Person(ifstream* file);
};


/*class Customer : public Person {
	int status;
	//Loan * loanlist[];
	Person* customerlist[];
	Customer::addCustomer(Person* per) {
		customerlist->push_back(per);
	}
};*/

class Employee : public Person {
};
#endif