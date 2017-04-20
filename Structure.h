#pragma once
#ifndef STRUCTURE
#define STRUCTURE
#include <string>
#include <iostream>
#include <time.h>
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
		cout << "Das Datum beträgt " << day<< ":" << month << ":" << year << endl;
	}
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
		cout << "direkt" << ts->tm_mday << ":" << ts->tm_mon << ":" << ts->tm_year << endl;
		cout << asctime(ts) << endl;
		day = ts->tm_mday;
		month =1 + ts->tm_mon;
		year = 1900 + ts->tm_year;
	}
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
		cout << street << " " << housnr << endl << ziplock << " " << town << endl;
	}
	Address() {};
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
		birthday.printDate();
	}
	Person() {};
	Person(string name, Address address, Date birthday) {
		this->name = name;
		this->address = address;
		this->birthday = birthday;
	}
};


class Customer : public Person {
	int status;
	Loan * loanlist[];
};

class Employee : public Person {
};
#endif