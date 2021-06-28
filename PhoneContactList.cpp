/*
 * CPhoneContact.cpp
 *
 *  Created on: 2016. 3. 28.
 *      Author: cskim
 */
#include <iostream>
#include <string>
#include "List.h"
#include <iomanip>
using namespace std;

#include "Entry.h"
#include "PhoneContactList.h"

ValueInfo viNull1;

PhoneContactList::PhoneContactList() { }

ValueInfo PhoneContactList::find(string name) const {
	LIter citer = findLocConst(name);
	if (citer==contactTable.end())
		return viNull1;
	return citer->valueInfo;
}
bool PhoneContactList::insert(string name, int number, string email){
	LIter iter = findLoc(name);

	if (iter != contactTable.end()){
		cout << "***Error -- Duplicated Name" << endl;
		return false;
	}
	else{
		contactTable.push_back(Entry(name, number, email));
	}

	return true;
}

bool PhoneContactList::remove(string name){
	LIter iter = findLoc(name);

	if (iter == contactTable.end()){
		cout << "***Error -- Name not found" << endl;
		return false;
	}
	else{
		contactTable.erase(iter);
	}

	return true;
}

void PhoneContactList::listAll() const{
	cout.setf(ios::left);
	LIter citer;

	cout << setw(10) << "Name" << setw(10) << "Number" << setw(20) << "Email" << endl;
	for (citer=contactTable.begin(); citer!=contactTable.end(); citer++){
		cout << setw(10) << citer->phoneName
			 << setw(10) << citer->valueInfo.phoneNumber
			 << setw(20) << citer->valueInfo.emailAddress << endl;
	}
}
LIter PhoneContactList::findLoc(string name){
	LIter iter;
	for (iter=contactTable.begin(); iter!=contactTable.end(); iter++){
		if (iter->phoneName == name)
			return iter;
	}
	return iter; // not found, iter==end()
}
LIter PhoneContactList::findLocConst (string name) const {
	LIter citer;
	for (citer=contactTable.begin(); citer!=contactTable.end(); citer++){
		if (citer->phoneName == name)
			return citer;
	}
	return citer; // not found, iter==end()
}

bool PhoneContactList::update(string name, int number, string email){
	if(!update(name, number))
		return false;
	else
		update(name, email);

	return true;
}

bool PhoneContactList::update(string name, int number){
	LIter iter = findLoc(name);

	if (iter == contactTable.end()){
		cout << "***Error -- Name not found" << endl;
		return false;
	}
	else {
		iter->valueInfo.phoneNumber = number;
	}

	return true;
}

bool PhoneContactList::update(string name, string email){
	LIter iter = findLoc(name);

	if (iter == contactTable.end()){
		cout << "***Error -- Name not found" << endl;
		return false;
	}
	else {
		iter->valueInfo.emailAddress = email;
	}

	return true;
}

string PhoneContactList::findName(int number) const {
	LIter citer = findLocFromNumber(number);

	if(citer == contactTable.end())
		return "";

	return citer->phoneName;
}

string PhoneContactList::findName(string email) const {
	LIter citer = findLocFromEmail(email);

	if(citer == contactTable.end())
		return "";

	return citer->phoneName;
}

LIter PhoneContactList::findLocFromNumber(int number) const {
	LIter citer;

	for (citer=contactTable.begin(); citer!=contactTable.end(); citer++){
		if (citer->valueInfo.phoneNumber == number)
			return citer;
	}

	return citer; // not found, iter==end()
}

LIter PhoneContactList::findLocFromEmail(string email) const {
	LIter citer;

	for (citer=contactTable.begin(); citer!=contactTable.end(); citer++){
		if (citer->valueInfo.emailAddress == email)
			return citer;
	}

	return citer; // not found, iter==end()
}
