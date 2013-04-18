/*
 * Uhrzeit.h
 *
 *  Created on: 20.06.2010
 *      Author: jule
 */

#ifndef UHRZEIT_H_
#define UHRZEIT_H_
#include <iostream>
#include <sstream>

#include "mein_zufall.h"

using namespace std;
class Uhrzeit{
	private:
		int stunde;
		int minute;
		int sekunde;
	public:
		Uhrzeit();
		~Uhrzeit();
		void zeige_uhrzeit();
		string get_uhrzeit();
};

#endif /* UHRZEIT_H_ */
