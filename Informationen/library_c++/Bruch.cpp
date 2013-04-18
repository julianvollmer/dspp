/*
 * Bruch.cpp
 *
 *  Created on: 02.05.2010
 *      Author: jule
 */

#include "Bruch.h"

Bruch::Bruch() {
	zaehler = 10;
	nenner = 5;
}

Bruch::Bruch( int der_zaehler, int der_nenner) {

	zaehler = der_zaehler;
	nenner = der_nenner;
}

int Bruch::liefere_zaehler() const {
	return zaehler;
}

int Bruch::liefere_nenner() const {
	return nenner;
}

void Bruch::kuerzen() {
	int der_ggt = ggt(zaehler, nenner);
	zaehler = zaehler / der_ggt;
	nenner = nenner / der_ggt;
}

Bruch Bruch::operator+(Bruch summand){
    zaehler = zaehler * summand.liefere_nenner() + summand.liefere_zaehler() * nenner;
    nenner  = nenner * summand.liefere_nenner();
    return *this;
}

Bruch Bruch::operator-(Bruch subtrahend){
    zaehler = zaehler * subtrahend.liefere_nenner() - subtrahend.liefere_zaehler() * nenner;
    nenner  = nenner * subtrahend.liefere_nenner();
    return *this;
}

bool Bruch::operator<(Bruch b){
	b=b;
	return false;
}
bool Bruch::operator>(Bruch b){
	b=b;
	return false;
}

bool Bruch::operator==(Bruch vgl)
{
    kuerzen();
    vgl.kuerzen();
    return (zaehler==vgl.zaehler && nenner==vgl.nenner);
}



