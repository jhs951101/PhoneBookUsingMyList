/*
 * CPhoneContact.h
 *
 *  Created on: 2016. 3. 28.
 *      Author: cskim
 */

#ifndef PHONECONTACTLIST_H_
#define PHONECONTACTLIST_H_

#include "List.h"
#include "Entry.h"
#include "PhoneContact.h"
/*
 *
 */
typedef Iterator LIter;

class PhoneContactList: public PhoneContact {
public:
	PhoneContactList();
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
	List contactTable;
	LIter findLoc(string name);
	LIter findLocConst (string name) const;
	LIter findLocFromNumber(int number) const;
	LIter findLocFromEmail(string email) const;
};

#endif /* PHONECONTACTLIST_H_ */
