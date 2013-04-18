/*
 * Studiengang.cpp
 *
 *  Created on: 20.06.2010
 *      Author: jule
 */

#include "Studiengang.h"
const char* def_studiengang[] = {"Abfallwirtschaft und Altlasten", "Aerospace Engineering (GIST-TUM Asia)", "Afrikanistik", "Afrikastudien", "Afrikastudien / African Studies", "Agrarhandel, Internationaler", "Agrarmanagement", "Agrarökonomie", "Agrarwirtschaft", "Agrarwissenschaften", "Agrarwissenschaften und Gartenbauwissenschaften", "Agrarwissenschaften, Ökologische", "Ägyptologie", "Akkordeon", "Albanologie", "Altertumswissenschaften - Ägyptologie", "Altertumswissenschaften - Altorientalistik", "Altertumswissenschaften - Klassische Archäologie", "Altertumswissenschaften - Prähistorische Archäologie", "Altertumswissenschaften - Religionswissenschaft", "Altertumswissenschaften - Vorderasiatische Altertumskunde", "Althebraistik", "Altorientalistik", "Altorientalistik (Assyriologie und Semitistik, Kleinasiatische Philologie)", "Altorientalistik / Hebraistik", "Altorientalistik mit Schwerpunkt Assyriologie", "Altorientalistik mit Schwerpunkt Vorderasiatische Archäologie", "Amerikanistik", "Amerikastudien (American Studies)", "Analytik und Spektroskopie", "Anglistik", "Anglistik / Amerikanistik", "Anthropologie, Biologische", "Antike Kulturen", "Antike Kulturen Ägyptens und Vorderasiens", "Antike Kulturen des östlichen Mittelmeerraumes", "Antike, Klassische. Geschichte und Literatur", "Application Architectures", "Arabistik", "Archäologie"};
const int anz_studiengang = sizeof(def_studiengang) / sizeof(def_studiengang[0]);
/**
 * Initialisiert einen Studiengang zufaellig.
 */
Studiengang::Studiengang(){
	int zufall = liefere_ganze_zufallszahl(0,(anz_studiengang - 1));
	studiengangnr = zufall;
	name = def_studiengang[zufall];
}
/**
 * Dekonstruktor für einen Studiengang.
 */
Studiengang::~Studiengang(){

}
/**
 * @return einen kompletten Studiengang.
 */

string Studiengang::get_studiengang(){
	ostringstream wandler(ios::out);
	  wandler  << name << " (" << studiengangnr << ")";
	  return wandler.str();
}
/**
 * Zeigt einen Studiengagn an;
 */
void Studiengang::zeige_studiengang(){
	cout << name << " (" << studiengangnr << ")" << endl;
}
/**
 * Erfasst einen Studiengangsnamen.
 */
void Studiengang::erfasse_name(){
	cout << "Bitte geben Sie den Studiengangsnamen ein : ";
	getline(cin,name);
}
/**
 * Erfasst eine Studiegansnr.
 */
void Studiengang::erfasse_studiengangnr(){
	cout << "Bitte geben sie die Studiengangsnr ein : ";
	cin >> name;
}
/**
 * Erfasst einen kompletten Studiengang.
 */
void Studiengang::erfasse_studiengang(){
	for(int i = 0; i < anz_studiengang; i++){
		cout << i + 1 << def_studiengang[i]<<endl;
	}
	int auswahl = (erfasse_int(1,anz_studiengang));
	studiengangnr = auswahl;
	name = def_studiengang[auswahl-1];
}
