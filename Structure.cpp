#include "stdafx.h"
#include "Structure.h"


Date::Date(ifstream *file) {
	Date::load(file);
}

 void Date::load(ifstream * file) {
	 string line;
	 getline(*file, line);
	 while (1) {
		 getline(*file, line);
		 string tag = parseLineTag(line);

		 if (tag == "Day") {
			 day = stoi(parseLineContent(line));
		 }
		 else if (tag == "Month") {
			month = stoi(parseLineContent(line));
		 }
		 else if (tag == "Year") {
			 year =stoi(parseLineContent(line));
		 }
		 else if (tag == "/Date") {
			 break;
		 }
		 else {
			 cout << "\n Parsing Error in Date";
		 }
	 }

}
 //string street;
 //string housnr;
 //string ziplock;
 //string town;

Address::Address(ifstream *file) {
	 Address::load(file);
 }

 void Address::load(ifstream *file) {
	 string line;
	 while (1) {
		 getline(*file, line);
		 string tag = parseLineTag(line);

		 if (tag == "Street") {
			 street = parseLineContent(line);
		 }
		 else if (tag == "Town") {
			 town = parseLineContent(line);
		 }
		 else if (tag == "Zipcode") {
			ziplock = parseLineContent(line);
		 }
		 else if (tag == "Number") {
			 housnr = parseLineContent(line);
		 }
		 else if (tag == "/Address") {
			 break;
		 }
		 else {
			 cout << "\n Parsing Error in Address";
		 }
	 }
 }


//Customer::Customer(fstream file) {
//	 Customer::load(file);
// }
////int status;
////Loan * loanlist[];
// void Customer::load(ifstream * file) {
//	 string line;
//	 while (1) {
//		 getline(file, line);
//		 string tag = parseLineTag(line);
//
//		 if (tag == "Street") {
//			 street = parseLineContent(line);
//		 }
//		 else if (tag == "Town") {
//			 town = parseLineContent(line);
//		 }
//		 else if (tag == "Zipcode") {
//			 ziplock = parseLineContent(line);
//		 }
//		 else if (tag == "Number") {
//			 housnr = parseLineContent(line);
//		 }
//		 else if (tag == "/Address") {
//			 break;
//		 }
//		 else {
//			 cout << "\n Parsing Error in Address";
//		 }
//	 }
// }