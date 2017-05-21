#pragma once
#ifndef MEDIEN
#define MEDIEN
#include <string>
#include <iostream>
#include <time.h>
#include <fstream>
#include "Parse.h"

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
		cout << "Abteilung: " << section << endl << "Regal " << rack << endl;
	}
	virtual void Location::load(ifstream * file);
	Location(string section, string rack) {
		this->section = section;
		this->rack = rack;
	}
	Location() {
		section = "Büro";
		rack = "Fach zum Einsortieren";
	}
	Location::Location(ifstream *file);
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
		cout << "Die Zeit betraegt " << h << ":" << min << ":" << sec << endl;
	}
	virtual void Time::load(ifstream * file);
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
		//cout << "Die aktuelle Datum betraegt: " << asctime(ts) << endl;
	}
	Time(short h, short min, short sec = 0) {
		this->h = h;
		this->min = min;
		this->sec = sec;
	}
};

class Medium {
	//static int Medium::medium_cnt = 0;
	//status stat;
	string title;
	string id;
	Location location;
	int fsk;
	int loanDays; // correct name??
public:
	enum status {
		ausgeliehen, verfuegbar, bestellt, reserviert, no_status
	}stat;

    string getStatus() {
    switch(stat) {
	case ausgeliehen:
		return "ausgeliehen";
	case verfuegbar:
		return "verfuegbar";
	case bestellt:
		return "bestellt";
	case reserviert:
		return "reserviert";
	case no_status:
		return "no_status";
	}
}

	void setStatus(string status);
	void printMedium() {
		cout << "Titel: " << title << "\nID: " << id << "\nAltersbeschraenkung: " << fsk << endl;
		location.printLocation();
	}
	/*int getCntObj() {
		return medium_cnt;
	}*/
	void setMedium() {
		 
	}

	Medium(string title, string id, Location l, int fsk, status stat) {
		stat = no_status;
		//medium_cnt++;
		this->title = title;
		this->id = id;
		this->location = l;
		this->fsk = fsk;
		this->stat = stat;

	}
	Medium::Medium(ifstream *file);
	virtual void Medium::load(ifstream * file);
	Medium() {
		stat = no_status;
		//medium_cnt++;
	}
	~Medium() {
		cout << "\nMedium " << title << " vernichtet" ;
		//medium_cnt--;
	}
};


class DVD : public Medium {
public:
	Time playingTime;
	virtual void DVD::load(ifstream * file);
};


class CD : public Medium{
public:
	int tracks;
	virtual void CD::load(ifstream * file);
};

class PrintedMedien : public Medium {
public:
	int pages;
	virtual void PrintedMedien::load(ifstream * file);
};

class Book : public PrintedMedien {
	virtual void Book::load(ifstream * file);
};

class Magazine : public PrintedMedien {
	virtual void Magazine::load(ifstream * file);
};

// Book with Audio CD
class AudioBook : public CD, public Book {
	virtual void AudioBook::load(ifstream * file);
};
#endif