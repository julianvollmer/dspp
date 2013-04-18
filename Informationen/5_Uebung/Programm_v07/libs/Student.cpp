/*
 * student.cpp
 *
 *  Created on: 12.06.2010
 *      Author: jule
 */

#ifndef STUDENT_CPP_
#define STUDENT_CPP_
#include "Student.h"

int matr = 100000;

Student::Student(){
	matrikelnummer = matr++;
}
Student::~Student(){

}

void Student::zeige_person(){
	Person::zeige_person();
	cout << setw(FELDBREITE) <<left << "Matrikelnummer"<<" : " << right << this->matrikelnummer << endl;
	cout << setw(FELDBREITE) <<left << "Fachbereich"<<" : " << right << fb.get_fachbereich() << endl;

}

void Student::erfasse_matrikelnummer(){
	cout << "Bitte geben Sie ihre Matrikelnummer ein";
	cin >> matrikelnummer;
}

void Student::erfasse_person(){
	Person::erfasse_person();
	fb.erfasse_fachbereich();
	sg.erfasse_studiengang();
	erfasse_matrikelnummer();
	imma_datum.erfasse_datum();
	ex_datum.erfasse_datum();
	heimat.erfasse_anschrift();
	email.erfasse_email();
}

int Student::get_matrikelnummer(){
	return this->matrikelnummer;
}

Fachbereich Student::get_fachbereich(){
	return this->fb;
}

bool vergleiche_student_matrikelnr(Student *s1, Student *s2) {
    bool first_arg_before = false;
    if (s1->get_matrikelnummer() < s2->get_matrikelnummer()) {
         first_arg_before = true;
    } else if (s1->get_matrikelnummer() > s2->get_matrikelnummer()) {
         first_arg_before = false;
    } else {
         first_arg_before = true;
    }
    return first_arg_before;
}
/**nach dem Fachbereich, bei gleichem Fachbereich alphabetisch nach dem Nachnamen, bei
gleichem Nachnamen nach dem Vornamen.
 */

bool vergleiche_student_fb_nachname_vorname(Student *p1, Student *p2) {
	bool is_richtig = false;
    if(p1->get_fachbereich().get_fachbereichsnummer() < p2->get_fachbereich().get_fachbereichsnummer()){
    	is_richtig = true;
    }else if (p1->get_fachbereich().get_fachbereichsnummer() > p2->get_fachbereich().get_fachbereichsnummer()){
    	is_richtig = false;
    }
    else{
    	if (p1->get_name().get_nachname() < p2->get_name().get_nachname()) {
    		is_richtig = true;
		} else if (p1->get_name().get_nachname() > p2->get_name().get_nachname()) {
			is_richtig = false;
		} else {
			 if (p1->get_name().get_vorname() < p1->get_name().get_vorname()) {
			  is_richtig = true;
			 } else if (p1->get_name().get_vorname() > p1->get_name().get_vorname()) {
			  is_richtig = false;
			 } else {
				 is_richtig = true;
			 }
		}
    }
	return is_richtig;
}

bool vergleiche_student_fb_matrikelnummer(Student *p1, Student *p2) {
	bool is_richtig = false;
    if(p1->get_fachbereich().get_fachbereichsnummer() < p2->get_fachbereich().get_fachbereichsnummer()){
    	is_richtig = true;
    }else if (p1->get_fachbereich().get_fachbereichsnummer() > p2->get_fachbereich().get_fachbereichsnummer()){
    	is_richtig = false;
    }
    else{
    	if (p1->get_matrikelnummer() < p2->get_matrikelnummer() ) {
    		is_richtig = true;
		} else if (p1->get_matrikelnummer() > p2->get_matrikelnummer()) {
			is_richtig = false;
		} else {
				 is_richtig = true;
			}

    }
	return is_richtig;
}
#endif /* STUDENT_CPP_ */
