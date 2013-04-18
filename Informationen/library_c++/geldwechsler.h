/*
 * geldwechsler.h
 *
 *  Created on: 13.05.2010
 *      Author: Veronika
 */

#ifndef GELDWECHSLER_H_
#define GELDWECHSLER_H_
#include <iostream>
#include <vector>
#include <time.h>
//#include <windows.h>
#include "eingabe.h"
#include "Geld.h"
#include "ausgabe.h"
using namespace std;
class Geldwechsler{
	private:
		vector<Geld> gueltiges_geld;
	public:
		void bezahlen(double betrag);
		Geld geld_einwerfen();
		void geld_auszahlen(double betrag);
		int zeige_geld(vector <Geld> p);
		void zeige_vector_geld(vector<Geld> p);
		void auszahlen_in_gueltigen_geld(double betrag);
		vector<Geld> initialisiere_gueltiges_geld();
		int erfasse_gueltiges_geld();
		Geldwechsler();
};


#endif /* GELDWECHSLER_H_ */
