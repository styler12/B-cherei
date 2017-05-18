#include "stdafx.h"
#include "Parse.h"


/*
* reads first tag in XML @line
*/
string parseLineTag(string line) {
	string tag;
	size_t first = line.find_first_of("<") + 1;
	//Tag starts
	size_t second = line.find_first_of(">");
	for (int i = first; i < second; i++) {
		tag.push_back(line.at(i));
	}
	return tag;
}

/*
* reads content between XML Tag in @line
*/
string parseLineContent(string line) {
	string end;
	for (int i = line.find_first_of(">")+1; i < line.length(); i++) {
		if (line.at(i) != '<')
			end.push_back(line.at(i));
		else {
			break;
		}
	}
	return end;
}