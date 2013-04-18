/*
 * geld.h
 *
 *  Created on: 14.05.2010
 *      Author: jule
 */

#ifndef GELD_H_
#define GELD_H_
#include <iostream>
using namespace std;
class Geld {
	private:
		double wert;
		string einheit;
	public:
		Geld(double der_wert);
		Geld();
		void zeige_wert() const;
		void zeige_einheit()const;
		void set_wert(double der_wert);
		double get_wert();
};


#endif /* GELD_H_ */
