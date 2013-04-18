/*
 * Bruch.h
 *
 *  Created on: 02.05.2010
 *      Author: jule
 */

#ifndef BRUCH_H_
#define BRUCH_H_
#include "meine_math.h"

class Bruch {

	private:
		int zaehler;
		int nenner;

	public:
		Bruch();
		Bruch(int der_zaehler, int der_nenner);
		int liefere_nenner() const;
		int liefere_zaehler() const;
		void kuerzen();
		Bruch operator+(Bruch b);
		Bruch operator-(Bruch b);
		bool operator<(Bruch summand);
		bool operator>(Bruch subtrahend);
		bool operator==(Bruch vgl);
};

#endif /* BRUCH_H_ */
