/*
 * Flug.h
 *
 *  Created on: 28.05.2010
 *      Author: julian
 */

#ifndef FLUG_H_
#define FLUG_H_
#include <iostream>
using namespace std;
#include "Flugzeug.h"
#include "mein_zufall.h"

class Flug {
	private:
		string start;
		string ziel;
		Flugzeug flieger;
		int anz_passagiere;
		double auslastung;

	public:
		Flug();
		Flug(Flugzeug f);
		string get_start();
		string get_ziel();
		Flugzeug get_flieger();
		void set_anz_passagiere(int die_passagiere);
		void set_start(string der_start);
		void set_ziel(string das_ziel);
		double get_auslastung();
		int get_anz_passagiere();
		void set_auslastung(double die_auslastung);
};

#endif /* FLUG_H_ */
