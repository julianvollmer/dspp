/*
 * Wochentag.h
 *
 *  Created on: 20.06.2010
 *      Author: jule
 */

#ifndef WOCHENTAG_H_
#define WOCHENTAG_H_
#include "mein_zufall.h"
#include "eingabe.h"
#include <iostream>
using namespace std;
class Wochentag{
	private:
		string name;
	public:
		Wochentag();
		~Wochentag();
		void zeige_wochentag();
		string get_wochentag_name();
		void erfasse_wochentag();
};

#endif /* WOCHENTAG_H_ */
