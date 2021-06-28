/*
 * PhoneContactMap.h
 *
 *  Created on: 2016. 4. 4.
 *      Author: cskim
 */

#ifndef PHONECONTACTMAP_H_
#define PHONECONTACTMAP_H_

#include <map>
#include "Entry.h"

typedef map<string, ValueInfo>::const_iterator MCIter;
typedef map<string, ValueInfo>::iterator MIter;
#include "PhoneContact.h"

class PhoneContactMap: public PhoneContact {
public:
	PhoneContactMap();
	bool insert(string name, int number, string email);
	bool update(string name, int number, string email);
	bool update(string name, int number);
	bool update(string name, string email);
	bool remove(string name);

	ValueInfo find(string name) const;
	string findName(int number) const;
	string findName(string email) const;

	void listAll()const;

private:
	map<string, ValueInfo> contactTable;
	MIter findLoc(string name);
	MCIter findLocConst (string name) const;
	MCIter findLocFromNumber(int number) const;
	MCIter findLocFromEmail(string email) const;
};

#endif /* PHONECONTACTMAP_H_ */
