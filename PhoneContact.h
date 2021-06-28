/*
 * PhoneContact.h
 *
 *  Created on: 2016. 4. 4.
 *      Author: cskim
 */

#ifndef PHONECONTACT_H_
#define PHONECONTACT_H_

#include <string>
using namespace std;

class PhoneContact {  // 생성자를 제외한 모든 함수가 순수 가상 함수, 서브클래스에서는 메소드 오버라이딩이 일어남
public:
	PhoneContact(){}
	virtual bool insert(string name, int number, string email)=0;
	virtual bool update(string name, int number, string email)=0;
	virtual bool update(string name, int number)=0;
	virtual bool update(string name, string email)=0;  // update() - 메소드 오버로딩
	virtual bool remove(string name)=0;

	virtual ValueInfo find(string name) const=0;
	virtual string findName(int number) const=0;
	virtual string findName(string email) const=0;  // findName() - 메소드 오버로딩

	virtual void listAll()const=0;
};

#endif /* PHONECONTACT_H_ */
