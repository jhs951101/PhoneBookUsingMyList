/*
 * PhoneContactVector.h
 *
 *  Created on: 2017. 3. 27.
 *      Author: cskim
 */

#ifndef PHONECONTACTVECTOR_H_
#define PHONECONTACTVECTOR_H_

#include <vector>
#include "Entry.h"
#include "PhoneContact.h"
/*
 *
 */
class PhoneContactVector: public PhoneContact {
public:
	PhoneContactVector();
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
	vector<Entry> vectorPhoneBook;
	int findLoc(string name) const;
	int findLocFromNumber(int number) const;
	int findLocFromEmail(string email) const;
};

#endif /* PHONECONTACTVECTOR_H_ */
