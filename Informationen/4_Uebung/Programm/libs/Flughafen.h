/*
 * Flughafen.h
 *
 *  Created on: 28.05.2010
 *      Author: julian
 */

#ifndef FLUGHAFEN_H_
#define FLUGHAFEN_H_
#include <iostream>
#include <vector>

#include "mein_zufall.h"
#include "Flugzeug.h"
using namespace std;


class Flughafen{
	private:
		string name;
		int max_flieger;
		int angekommen_durchsatz;
		int abgeflogen_durchsatz;
		vector<Flugzeug> flieger;

		string generiere_name();
		vector<Flugzeug> init_flieger();
		vector<Flugzeug> init_flieger_zufall(int anz);
	public:
		Flughafen();
		void set_name(string der_name);
		void set_durchsatz_abgeflogen(int der_abgeflogene_durchsatz);
		void set_durchsatz_angekommen(int der_angekommene_durchsatz);

		int get_max_flieger();
		string get_name();
		vector<Flugzeug> get_flieger();
		int get_durchsatz_angekommen();
		int get_durchsatz_abgeflogen();

		void erhoehe_durchsatz_angekommen(int der_angekommene_durchsatz);
		void erhoehe_durchsatz_abgefloggen(int der_abgeflogene_durchsatz);
		void loesche_flugezeug(int auswahl_flieger);
		void platziere_flugezeug(Flugzeug flugzeug);
};

#endif /* FLUGHAFEN_H_ */
