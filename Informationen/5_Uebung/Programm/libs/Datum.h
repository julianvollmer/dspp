/*
 * Datum.h
 *
 *  Created on: 13.06.2010
 *      Author: jule
 */

#ifndef DATUM_H_
#define DATUM_H_
#include <iostream>
#include <sstream>
#include "mein_zufall.h"
#include "eingabe.h"
using namespace std;
class Datum{
	private:
		int tag;
		int monat;
		int jahr;
	public:
		Datum();
		string get_datum_DE();
		string get_datum();
		void erfasse_jahr();
		void erfasse_monat();
		void erfasse_tag();
		void erfasse_datum();
		void setze_zufallsdatum();
		int get_tag();
		int get_monat();
		int get_jahr();
		void set_tag(int der_tag);
		void set_monat(int der_monat);
		void set_jahr(int das_jahr);
};

#endif /* DATUM_H_ */
