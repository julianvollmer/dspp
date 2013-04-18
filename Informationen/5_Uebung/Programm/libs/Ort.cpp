/*
 * Ort.cpp
 *
 *  Created on: 12.06.2010
 *      Author: jule
 */

#ifndef ORT_CPP_
#define ORT_CPP_
#include "Ort.h"
const char*  def_ort[] ={"Aach", "Aachen", "Aalen", "Abenberg", "Abensberg", "Achern", "Achim", "Adelsheim", "Adenau", "Adorf/Vogtl.", "Ahaus", "Ahrensburg", "Aichach", "Aken", "Albstadt", "Alfeld", "Allendorf", "Allstedt", "Alpirsbach", "Alsfeld", "Alsdorf", "AlslebenAltdorfbeiNürnberg", "Altena", "Altenau", "Altenberg", "Altenburg", "Altenkirchen", "Altensteig", "Altentreptow", "Altlandsberg", "Altötting", "Alzenau", "Alzey", "Amberg", "Amöneburg", "Amorbach", "Andernach", "Angermünde", "Anklam", "Hansestadt", "Annaberg-Buchholz", "Annaburg", "AnnweileramTrifels", "Ansbach", "Apolda", "Arendsee", "Arneburg", "Arnis", "Arnsberg", "Arnstadt", "Arnstein", "Arnstein", "Artern/Unstrut", "Arzberg", "Aschaffenburg", "Aschersleben", "Asperg", "Aßlar", "Attendorn", "Aub", "Aue", "AuerbachinderOberpfalz", "Auerbach/Vogtl.", "Augsburg", "Augustusburg", "Aulendorf", "Auma", "Aurich"};
const int anz_ort = sizeof(def_ort) / sizeof(def_ort[0]);

/**
 * Initialisiert einen Ort zufaellig.
 */
Ort::Ort(){
	ortsname = def_ort[liefere_ganze_zufallszahl(0,anz_ort - 1)];
	land = "Deutschland";
	for(int i = 0; i < 5; i++){
		plz+=liefere_ganze_zufallszahl(48,57);cout << endl << endl;

	}
}
/**
 * @return Gibt einen Ort zurueck.
 */
string Ort::get_ort(){
	return this->ortsname;
}
/**
 * @return Gibt die Postleitzahl zurueck
 */
string Ort::get_plz(){
	return this->plz;
}
/**
 * @return Gibt das Land zurueck.
 */
string Ort::get_land(){
	return this->land;
}
/**
 * Erfasst den Ortsnamen.
 */
void Ort::erfasse_ortsname(){
	cout << "Bitte geben Sie den Ortsname ein : ";
	getline(cin, ortsname);
}
/**
 * Erfasst die Postleitzahl
 */
void Ort::erfasse_plz(){
	cout << "Bitte geben Sie Postleitzahl ein";
	getline(cin, plz);
}
/**
 * Erfasst ein Land.
 */
void Ort::erfasse_land(){
	cout << "Bitte geben Sie das Land ein : ";
	getline(cin, land);
}
/**
 * Erfasst einen kompletten Ort
 */
void Ort::erfasse_ort(){
	erfasse_ortsname();
	erfasse_plz();
	erfasse_land();
}
#endif /* ORT_CPP_ */
