/*
 * main.h
 *
 *  Created on: 11.06.2010
 *      Author: jule
 */

#ifndef MAIN_H_
#define MAIN_H_
#include <iostream>
#include <vector>
#include <typeinfo>
#include <algorithm>
using namespace std;
#include "./libs/Person.h"
#include "./libs/Student.h"
#include "./libs/Mitarbeiter.h"
#include "./libs/Professor.h"
#include "./libs/ausgabe.h"
#include "./libs/mein_zufall.h"
int menu();
int erfasse_eingabe();
void verarbeite_eingabe(int weiter);


vector<Person *> erzeuge_personen_gemischt(int anz, vector<Person *> pvec);
vector<Person *> erzeuge_personen();
vector<Person *> verarbeite_eingabe(int weiter, vector<Person *> p);
void werte_eingabe_aus(int weiter);
void zeige_studenten(vector <Person *> &vect, bool (*cmp)(Student *p1, Student *p2));
vector<Student *> is_student(vector<Person *> pvec);
vector <Person *> erzeuge_studies(int anz, vector <Person *> pvec);
Person * erzeuge_person();
void zeige_gemischte_personen(vector <Person *> &vect, bool (*cmp)(Person *p1, Person *p2));
#endif /* MAIN_H_ */
