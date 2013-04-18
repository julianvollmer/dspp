/*
 * Automat.h
 *
 *  Created on: 17.05.2010
 *      Author: jule
 */

#ifndef AUTOMAT_H_
#define AUTOMAT_H_
#include <vector>
#include <iostream>
#include "Geld.h"
#include "ausgabe.h"
#include "Produkte.h"
#include "geldwechsler.h"
using namespace std;

class Automat{
	private:
		Geld g;
		Geldwechsler gw;
		vector<Produkte> p;
	public:
		Automat();
		void start();
		vector<Produkte> initialisiere_Produkte();
		int zeige_produkte(vector <Produkte> p);
};

#endif /* AUTOMAT_H_ */
