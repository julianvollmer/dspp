/*
 * Email.h
 *
 *  Created on: 13.06.2010
 *      Author: jule
 */

#ifndef EMAIL_H_
#define EMAIL_H_
#include <iostream>
using namespace std;

class Email{
	private:
		string email;
	public:
		Email();
		void set_email(string die_email);
		void zeige_email();
		void erfasse_email();
		string get_email();
};

#endif /* EMAIL_H_ */
