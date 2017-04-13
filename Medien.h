#pragma once
#ifndef MEDIEN
#define MEDIEN
#include "enums.h"
#include <string>

using namespace std;


class Location {
	string section; // correct name?
	string rack; // correct name?
};

class Time {
	short hour;
	short minute;
	short second;
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