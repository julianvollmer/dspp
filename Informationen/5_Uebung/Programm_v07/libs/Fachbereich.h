/*
 * Fachbereich.h
 *
 *  Created on: 20.06.2010
 *      Author: jule
 */

#ifndef FACHBEREICH_H_
#define FACHBEREICH_H_
#include <iostream>
#include <sstream>
#include "eingabe.h"
using namespace std;
class Fachbereich{
	private:
		string name;
		int bereichsnummer;
	public:
		Fachbereich();
		void zeige_fachbereich();
		void erfasse_name();
		void erfasse_bereichsnummer();
		void erfasse_fachbereich();
		string get_fachbereichsname();
		int get_fachbereichsnummer();
		void set_fachbereichsname(string der_name);
		void set_fachbereichsnummer(int die_bereichsnummer);
		string get_fachbereich();
};

#endif /* FACHBEREICH_H_ */
