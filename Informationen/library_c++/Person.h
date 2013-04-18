/*
 * person.h
 *
 *  Created on: 12.06.2010
 *      Author: jule
 */

#ifndef PERSON_H_
#define PERSON_H_
#include "Name.h"
#include "Anschrift.h"
//#include "Student.h"
#include "Ort.h"
#include "Telefon.h"
#include "Datum.h"
#include <iostream>
using namespace std;

class Person{
	private:
	Name name;
	Anschrift anschrift;
	string nationalitaet;
	Telefon telefon;
	Datum gebdat;
	Ort gebort;
	public:
		Person();
		virtual ~Person();
		virtual void zeige_person();
		virtual void erfasse_person();
		void erfasse_nationalitaet();
		Name get_name();
		Datum get_gebdat();
};
bool vergleiche_person_nachname_vorname_geb(Person *p1, Person *p2);
bool vergleiche_person_gebjahr_nachname_vorname(Person *p1, Person *p2);
bool vergleiche_person_geb_nachname_vorname(Person *p1, Person *p2);
#endif /* PERSON_H_ */
