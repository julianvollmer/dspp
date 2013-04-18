/*
 * professor.cpp
 *
 *  Created on: 12.06.2010
 *      Author: jule
 */
#ifndef PROFESSOR_CPP_
#define PROFESSOR_CPP_
#include "Professor.h"
#include <iostream>
using namespace std;

Professor::Professor(){

}

Professor::~Professor(){

}

void Professor::zeige_person(){
	Person::zeige_person();
	cout << setw(FELDBREITE) <<left << "Fachbereich"<<" : " << right << fb.get_fachbereich() << endl;
	cout << setw(FELDBREITE) <<left << "Studiengang"<<" : " << right << stg.get_studiengang() << endl;
	cout << setw(FELDBREITE) <<left << "Sprechstunde"<<" : " << right << spr.get_sprechstunde() << endl;
}


void Professor::erfasse_person(){
	Person::erfasse_person();
	fb.erfasse_fachbereich();
	stg.erfasse_studiengang();
	spr.erfasse_sprechstunde();
}


#endif /* PROFESSOR_CPP_ */
