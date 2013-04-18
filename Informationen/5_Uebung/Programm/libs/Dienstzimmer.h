/*
 * Dienstzimmer.h
 *
 *  Created on: 20.06.2010
 *      Author: jule
 */

#ifndef DIENSTZIMMER_H_
#define DIENSTZIMMER_H_
#include <iostream>
using namespace std;
#include "mein_zufall.h"

class Dienstzimmer{
	private:
		string gebaeude;
		string raum;
	public:
		Dienstzimmer();
		void zeige_dienstzimmer();
		void erfasse_gebaeude();
		void erfasse_raum();
		void erfasse_dienstzimmer();
		void set_gebaeude(string das_gebaeude);
		void set_raum(string der_raum);
		string get_gebaeude();
		string get_raum();
};

#endif /* DIENSTZIMMER_H_ */
