/*
 * Anschrift.h
 *
 *  Created on: 12.06.2010
 *      Author: jule
 */

#ifndef ANSCHRIFT_H_
#define ANSCHRIFT_H_

#include <iostream>
using namespace std;
#include "Ort.h"

class Anschrift{
	private:
		Ort ort;
		string strasse;
		int hausnummer;
	public:
		Anschrift();
		string get_strasse();
		int get_hausnummer();
		Ort get_ort();
		void erfasse_strasse();
		void erfasse_hausnummer();
		void erfasse_anschrift();
};

#endif /* ANSCHRIFT_H_ */
