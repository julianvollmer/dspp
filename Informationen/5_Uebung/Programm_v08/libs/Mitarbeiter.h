/*
 * Mitarbeiter.h
 *
 *  Created on: 12.06.2010
 *      Author: jule
 */


#ifndef MITARBEITER_H_
#define MITARBEITER_H_
#define FELDBREITE 30


//#include <algorithm>
//#include <cctype>
#include <string>
#include "Person.h"
#include "Dienstzimmer.h"
#include "Email.h"
#include "Telefon.h"
class Mitarbeiter : public Person{
	private:
		Dienstzimmer raum;
		Telefon telefon;
		Telefon fax;
		Email email;
		string funktion;
	public:
		Mitarbeiter();
		virtual ~Mitarbeiter();
		virtual void zeige_person();
		virtual void erfasse_person();
		void erfasse_funktion();
};

#endif /* MITARBEITER_H_ */

