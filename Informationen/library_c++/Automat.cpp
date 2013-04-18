/*
 * Automat.cpp
 *
 *  Created on: 17.05.2010
 *      Author: jule
 */
#include "Automat.h"
/**
 * Initialisiert einen Automaten mit Produkten.
 */
Automat::Automat(){
	p = initialisiere_Produkte();
}
/**
 * Startet den Automaten.
 */
void Automat::start(){

	int eingabe = -1;
	do{
		loesche_bildschirm_mit_header();
		eingabe = erfasse_int(-1, zeige_produkte(p) - 1 , "Bitte waehlen Sie Ihr Ziel");
		if (eingabe != -1){
			Produkte gewaehltes_produkt = p[eingabe];
			gw.bezahlen(gewaehltes_produkt.get_preis());
		}
	}while(eingabe != -1);

}

/**
 * Initialisiert einen Vector mit Produkten.
 * @return Vector mit den Produkten
 */
vector<Produkte> Automat::initialisiere_Produkte() {
      vector<Produkte> l;
      l.push_back(Produkte(77.80, "Berlin"));
      l.push_back(Produkte(12.30, "Hamburg"));
      l.push_back(Produkte(13.90, "Muenchen"));
      l.push_back(Produkte(61.90, "Goettingen"));
      l.push_back(Produkte(23.40, "Hannover"));
      l.push_back(Produkte(22.20, "Flensburg"));
      l.push_back(Produkte(18.50, "Magdeburg"));
      l.push_back(Produkte(37.50, "Hildesheim"));
      l.push_back(Produkte(25.50, "Kassel"));
      l.push_back(Produkte(29.90, "Dortmund"));
      l.push_back(Produkte(34.90, "Frankfurt"));
      l.push_back(Produkte(22.30, "Mainz"));
      return l;
}
/*
 * Zeigt alle Produkte und erfasst eine Auswahl aus den Produkten
 * @return Position des Produktes im Vector
 */
int Automat::zeige_produkte(vector <Produkte> p){
	int laenge = 0;
	for(vector<Produkte>::const_iterator it = p.begin(); it != p.end(); ++it){
		ios_base::fmtflags left[] = {cout.left};
		schreibe_text(p[laenge].get_name(), 20, '.', left, 1);
		cout << "("<< laenge << ")";
		cout << endl;
		laenge++;
	}
	return laenge;
}
