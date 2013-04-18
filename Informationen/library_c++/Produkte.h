/*
 * produkte.h
 *
 *  Created on: 17.05.2010
 *      Author: jule
 */

#ifndef PRODUKTE_H_
#define PRODUKTE_H_
#include <iostream>

using namespace std;
class Produkte {
	private:
		double preis;
		string name;

	public:
		void zeige_preis() const;
		void zeige_name() const;
		void zeige_fahrkarte() const;
		double get_preis() const;
		string get_name() const;
		Produkte();
		Produkte(double der_preis, string der_name);
};


#endif /* PRODUKTE_H_ */
