/*
 * geldwechsler.cpp
 *
 *  Created on: 13.05.2010
 *      Author: Jule
 */

#include "geldwechsler.h"

/**
 * Initilisiert den Geldwechsler mit gueltigen Geld.
 */
Geldwechsler::Geldwechsler() {
	gueltiges_geld = initialisiere_gueltiges_geld();
}
/**
 * Fordert den Benutzer auf gueltiges Geld einzugeben.
 * @param betrag Betrag der gezahlt werden soll
 */
void Geldwechsler::bezahlen(double betrag) {
	double ori_preis = betrag;
	ios_base::fmtflags left[] = { cout.left, cout.fixed };
	vector<Geld> vec;
	bool abbruch = false;
	while (betrag >= 0 && !abbruch) {
		loesche_bildschirm_mit_header();
		cout << "Der Preis betraegt: ";
		schreibe_zahl(ori_preis, 0, '.', left, 2, 2);
		cout << endl;
		cout << "Der Restbetrag ist: ";
		schreibe_zahl(betrag, 0, '.', left, 2, 2);
		cout << endl << endl;
		Geld g = geld_einwerfen();
		vec.push_back(g);
		if((int)(g.get_wert()) == -1){
			abbruch=true;
		}
		else{
			betrag -= g.get_wert();
		}
	}
	if (abbruch){
		zeige_vector_geld(vec);
	}
	else{
		geld_auszahlen(betrag);
	}
}
/**
 * Forder den Benutzer auf Geld einzuwerfen
 */
Geld Geldwechsler::geld_einwerfen() {
	return gueltiges_geld[erfasse_gueltiges_geld()];
}
/**
 * Zahlt den Betrag in gueltigem Geld aus.
 * @param betrag Betrag der ausgezahlt werden soll.
 */

void Geldwechsler::geld_auszahlen(double betrag) {
	if(betrag < 0 )
		betrag = betrag * (-1);
	ios_base::fmtflags left[] = { cout.left, cout.fixed };
	cout << "Der Restbetrag von ";
	schreibe_zahl(betrag, 0, '.', left, 2, 2);
	cout << " wird nun ausgezahlt" << endl;
	auszahlen_in_gueltigen_geld(betrag);
}
/**
 * Zahlt den Betrag in gueltigem Geld aus
 * @param betrag Betrag der ausgezahlt werden soll.
 */
void Geldwechsler::auszahlen_in_gueltigen_geld(double betrag) {
	ios_base::fmtflags left[] = { cout.left, cout.fixed };
	if (betrag < 0)
		betrag = betrag * (-1);
	cout << "Die Auszahlung erfolgt in folgender Stueckelung:" << endl;
	for (int i = gueltiges_geld.size() - 1; i >= 0; i--) {
		int anz = 0;
		while (((int)(betrag*100) - (int)(gueltiges_geld[i].get_wert())*100) >= 0 && ((int)gueltiges_geld[i].get_wert()) != -1) {
			betrag -= gueltiges_geld[i].get_wert();
			anz++;
		}
		if(((int)gueltiges_geld[i].get_wert()) != -1){
			cout << anz << " x ";
			schreibe_zahl(gueltiges_geld[i].get_wert(), 0, '.', left, 2, 2);
			cout << endl;
		}

	}
	wait();
}

/**
 * Initialisiert einen Vector mit gueltigen Geldwerten.
 * @return Vector mir gueltigem Geld.
 */
vector<Geld> Geldwechsler::initialisiere_gueltiges_geld() {
	vector<Geld> l;
	l.push_back(Geld(-1.0));
	l.push_back(Geld(0.10));
	l.push_back(Geld(0.20));
	l.push_back(Geld(0.50));
	l.push_back(Geld(1.00));
	l.push_back(Geld(2.00));
	l.push_back(Geld(5.00));
	l.push_back(Geld(10.0));
	l.push_back(Geld(20.00));
	l.push_back(Geld(50.00));
	return l;
}

/**
 * Zeigt das gueltige Geld an.
 * @param p Vector mit gueltigen Geld
 */
int Geldwechsler::zeige_geld(vector<Geld> p) {
	int laenge = 0;
	for (vector<Geld>::const_iterator it = p.begin(); it != p.end(); ++it) {
		ios_base::fmtflags left[] = { cout.left, cout.fixed };
		if(p[laenge].get_wert() > 0){
			schreibe_zahl(p[laenge].get_wert(), 20, '.', left, 2, 2);
			cout << "(" << laenge + 1 << ")";
			cout << endl;
			laenge++;
		}
	}
	return laenge;
}
/**
 * Erfasst vom Benutzer einen Betrag.
 * @return Position an dem der Betrag im Vector steht.
 */
int Geldwechsler::erfasse_gueltiges_geld() {
	unsigned int pos = 0;
	bool eingabe_ok = false;
	while (!eingabe_ok) {
		cout << "Bitte werfen die gueltiges Geld ein:" << endl;
		double betrag = erfasse_double(-1.0,50.0);
		pos = 0;
		for (vector<Geld>::const_iterator it = gueltiges_geld.begin(); it != gueltiges_geld.end() && !eingabe_ok; ++it) {
			if ((int) (gueltiges_geld[pos].get_wert() * 100) == (int) (betrag * 100)) {
				eingabe_ok = true;
			}
			else
				pos++;
		}
	}
	return pos;
}

/**
 * Gibt das eingegebene Geld aus.
 * @param p Vector mit dem eingeworfenen Geld.
 */
void Geldwechsler::zeige_vector_geld(vector<Geld> p) {
	int laenge = 0;
	cout << "Sie haben folgendes Geld eingeworfen :" << endl;
	for (vector<Geld>::const_iterator it = p.begin(); it != p.end(); ++it) {
		ios_base::fmtflags left[] = { cout.left, cout.fixed };
		if(p[laenge].get_wert() > 0){
			schreibe_zahl(p[laenge].get_wert(), 0, '.', left, 2, 2);
			p[laenge].zeige_einheit();
			cout << endl;
			laenge++;
		}
	}
	wait();
}
