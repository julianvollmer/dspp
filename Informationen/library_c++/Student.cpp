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
/**
 * Intialisiert einen Studenten mit zufallswerten.
 */
Student::Student(){
	matrikelnummer = matr++;
	imma_datum.setze_zufallsdatum();
	ex_datum.set_tag(1);
	ex_datum.set_monat(liefere_ganze_zufallszahl(1,12));
	ex_datum.set_jahr(imma_datum.get_jahr() + liefere_ganze_zufallszahl(1,20));
}

Student::~Student(){

}
/**
 * Schreibt eine Person auf den Bildschirm.
 */
void Student::zeige_person(){
	Person::zeige_person();
	cout << setw(FELDBREITE) <<left << "Matrikelnummer"<<" : " << right << this->matrikelnummer << endl;
	cout << setw(FELDBREITE) <<left << "Fachbereich"<<" : " << right << fb.get_fachbereich() << endl;
	cout << setw(FELDBREITE) <<left << "Studiengang"<<" : " << right << sg.get_studiengang() << endl;
	cout << setw(FELDBREITE) <<left << "Immatrikulationsdatum"<<" : " << right << imma_datum.get_datum_DE() << endl;
	cout << setw(FELDBREITE) <<left << "Exmatrikulationsdatum"<<" : " << right << ex_datum.get_datum_DE() << endl;
	cout << setw(FELDBREITE) <<left << "Heimanschrift"<<" : " << heimat.get_strasse() << " " << heimat.get_hausnummer() << endl;
	cout << setw(FELDBREITE + 3) <<left << " "<< heimat.get_ort().get_plz() << " " << heimat.get_ort().get_ort() << endl;
	cout << setw(FELDBREITE + 3) <<left << " "<<  heimat.get_ort().get_land() << endl;
	cout << setw(FELDBREITE) <<left << "Emailadresse"<<" : " << right << ex_datum.get_datum_DE() << endl;
}

/**
 * Erfasst eine Matrikelnummer.
 */
void Student::erfasse_matrikelnummer(){
	cout << "Bitte geben Sie ihre Matrikelnummer ein";
	cin >> matrikelnummer;
}
/**
 * Erfasst einen Studenten
 */

void Student::erfasse_person(){
	Person::erfasse_person();
	cout << "Bitte geben sie ihren Fachbereich ein" << endl;
	fb.erfasse_fachbereich();
	cout << "Bitte geben sie ihr Studiengang ein" << endl;
	sg.erfasse_studiengang();
	this->matrikelnummer = matr++;
	cout << "Bitte geben sie ihr Immatrikulationsdatum ein" << endl;
	imma_datum.erfasse_datum();
	cout << "Bitte geben sie ihr Exmatrikulationsdatum ein" << endl;
	ex_datum.erfasse_datum();
	cout << "Bitte geben sie ihr Heimadresse ein" << endl;
	heimat.erfasse_anschrift();
	cout << "Bitte geben sie ihr Emailadresse ein" << endl;
	email.erfasse_email();
}

/**
 * @return Gibt die Matrikelnummer eines Studenten zurueck.
 */
int Student::get_matrikelnummer(){
	return this->matrikelnummer;
}
/**
 * @return Gibt den Fachbereich zurueck.
 */
Fachbereich Student::get_fachbereich(){
	return this->fb;
}
/**
 * Vergleicht 2 Studenten anhand ihrer Matrikelnummer
 */
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
/**
 * Vergleicht 2 Studenten nach dem Fachbereich, bei gleichem Fachbereich alphabetisch nach dem Nachnamen, bei
 * gleichem Nachnamen nach dem Vornamen.
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
/**
 * Vergleicht 2 Studenten anhand ihrer Fachbereichsnummer und dann anhand ihrer Matrikelnummer.
 */
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
