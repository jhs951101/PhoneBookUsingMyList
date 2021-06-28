/*
 * PhoneContactMap.cpp
 *
 *  Created on: 2016. 4. 4.
 *      Author: cskim
 */

#include <iostream>
#include <string>
#include <map>
#include <iomanip>
using namespace std;

#include "Entry.h"
#include "PhoneContactMap.h"

ValueInfo viNull3;

PhoneContactMap::PhoneContactMap() { }

ValueInfo PhoneContactMap::find(string name) const {
	MCIter citer = findLocConst(name);

	if (citer==contactTable.end())
		return viNull3;

	return contactTable.at(name);
}

bool PhoneContactMap::insert(string name, int number, string email){
	MIter iter = findLoc(name);

	if (iter != contactTable.end()){  // insert
		cout << "***Error -- Duplicated Name" << endl;
		return false;
	}
	else {
		contactTable[name] = ValueInfo(number, email);
	}

	return true;
}

bool PhoneContactMap::remove(string name){
	MIter iter = contactTable.find(name);

	if (iter == contactTable.end()){
		cout << "***Error -- Name not found" << endl;
		return false;
	}
	else{
		contactTable.erase(iter);
	}

	return true;
}

void PhoneContactMap::listAll() const {
	cout.setf(ios::left);
	MCIter citer;

	cout << setw(10) << "Name" << setw(10) << "Number" << setw(20) << "Email" << endl;
	for (citer=contactTable.begin(); citer!=contactTable.end(); citer++){
		cout << setw(10) << citer->first
			 << setw(10) << citer->second.phoneNumber
			 << setw(20) << citer->second.emailAddress << endl;
	}
}

bool PhoneContactMap::update(string name, int number, string email){
	if(!update(name, number))
		return false;
	else
		update(name, email);

	return true;
}

bool PhoneContactMap::update(string name, int number){
	MIter iter = findLoc(name);

	if (iter == contactTable.end()){
		cout << "***Error -- Name not found" << endl;
		return false;
	}
	else {
		iter->second.phoneNumber = number;
	}

	return true;
}

bool PhoneContactMap::update(string name, string email){
	MIter iter = findLoc(name);

	if (iter == contactTable.end()){
		cout << "***Error -- Name not found" << endl;
		return false;
	}
	else {
		iter->second.emailAddress = email;
	}

	return true;
}

string PhoneContactMap::findName(int number) const {
	MCIter citer = findLocFromNumber(number);

	if(citer == contactTable.end())
		return "";

	return citer->first;
}

string PhoneContactMap::findName(string email) const {
	MCIter citer = findLocFromEmail(email);

	if(citer == contactTable.end())
		return "";

	return citer->first;
}

MIter PhoneContactMap::findLoc(string name) {
	MIter iter;
	for (iter=contactTable.begin(); iter!=contactTable.end(); iter++){
		if (iter->first == name)
			return iter;
	}
	return iter; // not found, CIter==end()
}

MCIter PhoneContactMap::findLocConst(string name) const {
	MCIter citer;
	for (citer=contactTable.begin(); citer!=contactTable.end(); citer++){
		if (citer->first == name)
			return citer;
	}
	return citer; // not found, CIter==end()
}

MCIter PhoneContactMap::findLocFromNumber(int number) const {
	MCIter citer;

	for (citer=contactTable.begin(); citer!=contactTable.end(); citer++){
		if (citer->second.phoneNumber == number)
			return citer;
	}

	return citer; // not found, CIter==end()
}

MCIter PhoneContactMap::findLocFromEmail(string email) const {
	MCIter citer;

	for (citer=contactTable.begin(); citer!=contactTable.end(); citer++){
		if (citer->second.emailAddress == email)
			return citer;
	}

	return citer; // not found, CIter==end()
}
