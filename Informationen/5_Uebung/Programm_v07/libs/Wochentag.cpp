/*
 * Wochentag.cpp
 *
 *  Created on: 20.06.2010
 *      Author: jule
 */
#include "Wochentag.h"

string def_wochentage[] = {"Montag", "Dienstag", "Mittwoch", "Donnerstag", "Freitag" , "Samstag", "Sonntag"};
int anz_wochentage = sizeof(def_wochentage) / sizeof(def_wochentage[0]);


Wochentag::Wochentag(){
	name = def_wochentage[liefere_ganze_zufallszahl(0, (anz_wochentage - 1))];
}

Wochentag::~Wochentag(){

}

void Wochentag::zeige_wochentag(){
	cout << name << endl;
}

string Wochentag::get_wochentag_name(){
	return this->name;
}

void Wochentag::erfasse_wochentag(){

	for(int i = 0; i < anz_wochentage; i++ ){
		cout << endl << "(" << i+1 << ")" << def_wochentage[i];
	}
	cout << endl << "Bitte waehlen Sie einen der Wochentag : ";
	name = def_wochentage[erfasse_int(1,anz_wochentage) - 1 ];
}
