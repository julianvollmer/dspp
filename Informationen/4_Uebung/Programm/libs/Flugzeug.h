/*
 * Flugzeug.h
 *
 *  Created on: 28.05.2010
 *      Author: julian
 */

#ifndef FLUGZEUG_H_
#define FLUGZEUG_H_
#include <iostream>
using namespace std;

class Flugzeug{
	private:
		string name;
		int max_passagiere;
	public:
		Flugzeug();
		Flugzeug(string der_name, int die_max_passagiere);
		string get_name();
		int get_max_passagiere();
		double get_auslastung(double passagiere_an_board );
};

#endif /* FLUGZEUG_H_ */
