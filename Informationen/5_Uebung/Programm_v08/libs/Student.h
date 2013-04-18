/*
 * Student.h
 *
 *  Created on: 12.06.2010
 *      Author: jule
 */
#ifndef STUDENT_H_
#define STUDENT_H_
#include "Person.h"
#include "Datum.h"
#include "Email.h"
#include "Fachbereich.h"
#include "Studiengang.h"

class Student : public Person{
	private:
		Fachbereich fb;
		Studiengang sg;
		int matrikelnummer;
		Datum imma_datum;
		Datum ex_datum;
		Anschrift heimat;
		Email email;

	public:
		Student();
		virtual ~Student();
		virtual void zeige_person();
		virtual void erfasse_person();
		void erfasse_matrikelnummer();
		int get_matrikelnummer();
		Fachbereich get_fachbereich();
};
bool vergleiche_student_matrikelnr(Student *s1, Student *s2);
bool vergleiche_student_fb_nachname_vorname(Student *p1, Student *p2);
bool vergleiche_student_fb_matrikelnummer(Student *p1, Student *p2);



#endif /* STUDENT_H_ */
