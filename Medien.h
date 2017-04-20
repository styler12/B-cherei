#pragma once
#ifndef MEDIEN
#define MEDIEN
#include "enums.h"
#include <string>

using namespace std;


class Location {
private:
	string section; 
	string rack; 
public:
	string getSection() {
		return section;
	}
	string getRack() {
		return rack;
	}
	void setRack(string rack) {
		this->rack = rack;
	}
	void setSection(string section) {
		this->section = section;
	}
	void printLocation() {
		cout << "section: " << section << endl << "Rack " << rack << endl;
	}
	Location(string section, string rack) {
		this->section = section;
		this->rack = rack;
	}
	Location() {
		section = "Büro";
		rack = "Fach zum Einsortieren";
	}
};

class Time {
private:
	short h;
	short min;
	short sec;

	time_t t;
	tm * ts;
public:
	short gethour() {
		return h;
	}
	short getminute() {
		return min;
	}
	short getsecond() {
		return sec;
	}
	void setHour(short h) {
		this->h = h;
	}
	void setMinute(short min) {
		this->min = min;
	}
	void setSec(short sec) {
		this->sec = sec;
	}
	void printTime() {
		cout << "Die Zeit beträgt " << h << ":" << min << ":" << sec << endl;
	}
	/*
	* set custom time
	* @day
	* @month
	* @year
	*/
	void setTime(short h, short min, short sec) {
		ts->tm_hour = h;
		ts->tm_min = min;
		ts->tm_sec = sec;
	}
	/*
	*set actual Time
	*/
	void updateTime() {
		t = time(NULL); //revert time since 1970 in sec
		ts = localtime(&t); // convert time in stuct
		h = ts->tm_hour;
		min = ts->tm_min;
		sec = ts->tm_sec;
	}
	Time() {
		updateTime();
		//cout << "Die aktuelle Datum beträgt: " << asctime(ts) << endl;
	}
	Time(short h, short min, short sec = 0) {
		this->h = h;
		this->min = min;
		this->sec = sec;
	}
};

class Medium {
public:
	status status;
	string title;
	string id;
	Location location;
	int loanDays; // correct name??

};


class DVD : public Medium {
public:
	Time playingTime;
};


class CD : public Medium{
public:
	int tracks;
};

class PrintedMedien : public Medium {
public:
	int pages;
};

class Book : public PrintedMedien {
};

class Magazine : public PrintedMedien {
};

// Book with Audio CD
class AudioBook : public CD, public Book {
};
#endif