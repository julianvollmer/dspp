/*
 * Name.h
 *
 *  Created on: 12.06.2010
 *      Author: jule
 */

#ifndef NAME_H_
#define NAME_H_
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;
#include "mein_zufall.h"
#include "eingabe.h"
#define FELDBREITE 30

class Name{
	private:
		string vorname;
		string nachname;
		string title;
		string geburtsname;
		char geschlecht;
	public:
		Name();
		virtual ~Name();

		string get_vorname();
		string get_nachname();
		string get_geburtsname();
		string get_title();
		void set_vorname(string der_vorname);
		void set_nachname(string der_nachnam);
		void set_geburtsname(string das_geburtsdatum);
		void set_title(string der_title);
		char get_geschlecht();
		void erfasse_vorname();
		void erfasse_nachname();
		void erfasse_title();
		void erfasse_geschlecht();
		void erfasse_geburtsname();
		void erfasse_name();

};


#endif /* NAME_H_ */
