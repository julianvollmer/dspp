/*
 * Person.cpp
 *
 *  Created on: 12.06.2010
 *      Author: jule
 */

#ifndef PERSON_CPP_
#define PERSON_CPP_
#include "Person.h"

const string def_nationalitaeten[] ={"Ägypten", "Äquatorialguinea", "Äthiopien", "Afghanistan", "Albanien", "Algerien", "Andorra", "Angola", "Antigua und Barbuda", "Argentinien", "Armenien", "Aserbaidschan", "Australien", "Bahamas", "Bahrain", "Bangladesch", "Barbados", "Belgien", "Belize", "Benin", "Bhutan", "Bolivien", "Bosnien und Herzegowina", "Botsuana", "Brasilien", "Brunei", "Bulgarien", "Burkina Faso", "Burundi", "Chile", "China", "Costa Rica", "Dänemark", "Deutschland", "Dominica", "Dominikanische Republik", "Dschibuti", "Ecuador", "El Salvador", "Elfenbeinküste", "Eritrea", "Estland", "Fidschi", "Finnland", "Frankreich", "Gabun", "Gambia", "Georgien", "Ghana", "Grenada", "Griechenland", "Großbritannien", "Guatemala", "Guinea", "Guinea-Bissau", "Guyana", "Haiti", "Honduras", "Indien", "Indonesien", "Irak", "Iran", "Irland", "Island", "Israel", "Italien", "Jamaika", "Japan", "Jemen", "Jordanien", "Kambodscha", "Kamerun", "Kanada", "Kap Verde", "Kasachstan", "Katar", "Kenia", "Kirgistan", "Kiribati", "Kolumbien", "Komoren", "Kongo, Republik", "Kongo, Demokratische Republik", "Kroatien", "Kuba", "Kuwait", "Laos", "Lesotho", "Lettland", "Libanon", "Liberia", "Libyen", "Liechtenstein", "Litauen", "Luxemburg", "Madagaskar", "Malawi", "Malaysia", "Malediven", "Mali", "Malta", "Marokko", "Marshallinseln", "Mauretanien", "Mauritius", "Mazedonien", "Mexiko", "Mikronesien", "Moldawien", "Monaco", "Mongolei", "Montenegro", "Mosambik", "Myanmar", "Namibia", "Nauru", "Nepal", "Neuseeland", "Nicaragua", "Niederlande", "Niger", "Nigeria", "Niue", "Nordkorea", "Norwegen", "Österreich", "Oman", "Pakistan", "Palau", "Palästinensische Gebiete", "Panama", "Papua-Neuguinea", "Paraguay", "Peru", "Philippinen", "Polen", "Portugal", "Ruanda", "Rumänien", "Russland", "Sahara", "Salomonen", "Sambia", "Samoa", "San Marino", "São Tomé und Príncipe", "Saudi-Arabien", "Schweden", "Schweiz", "Senegal", "Serbien", "Seychellen", "Sierra Leone", "Simbabwe", "Singapur", "Slowakei", "Slowenien", "Somalia", "Spanien", "Sri Lanka", "St. Kitts und Nevis", "St. Lucia", "St. Vincent und die Grenadinen", "Sudan", "Südafrika", "Südkorea", "Suriname", "Swasiland", "Syrien", "Tadschikistan", "Taiwan", "Tansania", "Thailand", "Timor-Leste", "Togo", "Tonga", "Trinidad und Tobago", "Tschad", "Tschechien", "Tunesien", "Turkmenistan", "Turks- und Caicosinseln", "Tuvalu", "Türkei", "Uganda", "Ukraine", "Ungarn", "Uruguay", "USA", "Usbekistan", "Vanuatu", "Vatikanstadt", "Venezuela", "Vereinigte Arabische Emirate", "Vietnam", "Weißrussland", "Zentralafrikanische Republik", "Zypern"};
const int anz_nationalitaeten = sizeof(def_nationalitaeten) / sizeof(def_nationalitaeten[0]);
/**
 * Initilisiert eine Person zufaellig.
 */
Person::Person(){
	nationalitaet = def_nationalitaeten[liefere_ganze_zufallszahl(0, (anz_nationalitaeten - 1) )];
	gebdat.setze_zufallsdatum();
}
Person::~Person(){

}

/**
 * Schreibt einen Person auf den Bildschirm.
 */
/*
Name name;
Anschrift anschrift;
string nationalitaet;
Telefon telefon;
Datum gebdat;
Ort gebort;
*/
void Person::zeige_person(){
	cout << setw(FELDBREITE) <<left << "Title"<<" : " << right << name.get_title() << endl;
	cout << setw(FELDBREITE) <<left << "Vorname"<<" : " << right << name.get_vorname() << endl;
	cout << setw(FELDBREITE) <<left << "Nachname"<<" : " << right << name.get_nachname()<< endl;
	cout << setw(FELDBREITE) <<left << "Geschlecht"<<" : " << right << name.get_geschlecht() << endl;
	cout << setw(FELDBREITE) <<left << "Geburtsdatum"<<" : " << right << gebdat.get_datum_DE() << endl;
	cout << setw(FELDBREITE) <<left << "Anschrift"<<" : " << anschrift.get_strasse() << " " << anschrift.get_hausnummer() << endl;
	cout << setw(FELDBREITE + 3) <<left << " "<< anschrift.get_ort().get_plz() << " " << anschrift.get_ort().get_ort() << endl;
	cout << setw(FELDBREITE + 3) <<left << " "<<  anschrift.get_ort().get_land() << endl;
	cout << setw(FELDBREITE) <<left << "Nationalitaet"<<" : " << right <<this->nationalitaet << endl;
	cout << setw(FELDBREITE) <<left << "Telefon"<<" : " << right << telefon.get_telefon()<<endl;
	cout << setw(FELDBREITE) <<left << "Gebortsort"<<" : "<< gebort.get_plz() << " " << gebort.get_ort()<<", " << gebort.get_land() << endl;
}
/**
 * Erfasst die Nationalitaet einer Person.
 */
void Person::erfasse_nationalitaet(){
	cout << "Bitte geben Sie ihre Nationalitaet ein : ";
	getline(cin, nationalitaet);
}
/**
 * Erfasst einen komplette Person
 */
void Person::erfasse_person(){
	cout << "Bitte geben Sie die Informationen zum Namen ein!" << endl;
	name.erfasse_name();
	cout << "Bitte geben Sie die Informationen zur Anschrift ein!" << endl;
	anschrift.erfasse_anschrift();
	cout << "Bitte geben Sie die Informationen ueber ihre Nationalitaet ein!" << endl;
	erfasse_nationalitaet();
	cout << "Bitte geben Sie die Informationen zur Telefonnummer ein!" << endl;
	telefon.erfasse_telefon();
	cout << "Bitte geben Sie die Informationen zu Ihrem Geburtsdatum ein" << endl;
	gebdat.erfasse_datum();
	cout << "Bitte geben Sie die Informationen zu ihrem Geburtstort ein!" << endl;
	gebort.erfasse_ort();
}

/**
 * @return Gibt den Namen zurueck.
 */
Name Person::get_name(){
	return this->name;
}
/**
 * @return Gibt das Geburtsdatum zurueck
 */
Datum Person::get_gebdat(){
	return this->gebdat;
}

/**
 * Vergleicht zwei Personen miteinander. (Nachname, Vorname, Geburtsdatum)
 * @param *p1 Die Person Eins.
 * @param *p2 Die Person Zwei.
 * @return True, wenn das erste Argument vor dem zweiten Argument eingeordet werden soll.
 */
bool vergleiche_person_nachname_vorname_geb(Person *p1, Person *p2) {
     bool is_richtig = false;
     if (p1->get_name().get_nachname() < p2->get_name().get_nachname()) {
    	 is_richtig = true;
     } else if (p1->get_name().get_nachname() > p2->get_name().get_nachname()) {
    	 is_richtig = false;
     } else {
          if (p1->get_name().get_vorname() < p1->get_name().get_vorname()) {
        	  is_richtig = true;
          } else if (p1->get_name().get_vorname() > p1->get_name().get_vorname()) {
        	  is_richtig = false;
          } else {
               if (p1->get_gebdat().get_datum() < p2->get_gebdat().get_datum()) {
            	   is_richtig = true;
               } else if (p1->get_gebdat().get_datum() > p2->get_gebdat().get_datum() ) {
            	   is_richtig = false;
               } else {
            	   is_richtig = true;
               }
          }
     }
     return is_richtig;
}
/**
 * Vergleicht Personen nach dem Geburtsdatum, bei gleichem Geburtsdatum nach dem Nachnamen, bei gleichem
 * Nachnamen nach dem Vornamen;
 * @param *p1 Person 1.
 * @param *p2 Person 2.
 * @return True, wenn das erste Argument vor dem zweiten Argument eingeordet werden soll.
 **/
bool vergleiche_person_gebjahr_nachname_vorname(Person *p1, Person *p2) {
	bool is_richtig = false;
    if(p1->get_gebdat().get_jahr() < p2->get_gebdat().get_jahr()){
    	is_richtig = true;
    }else if (p1->get_gebdat().get_jahr() > p2->get_gebdat().get_jahr()){
    	is_richtig = false;
    }
    else{
    	if (p1->get_name().get_nachname() < p2->get_name().get_nachname()) {
    		is_richtig = true;
		} else if (p1->get_name().get_nachname() > p2->get_name().get_nachname()) {
			is_richtig = false;
		} else {
			 if (p1->get_name().get_vorname() < p1->get_name().get_vorname()) {
			  is_richtig = true;
			 } else if (p1->get_name().get_vorname() > p1->get_name().get_vorname()) {
			  is_richtig = false;
			 } else {
				 is_richtig = true;
			 }
		}

    }

	return is_richtig;
}

bool vergleiche_person_geb_nachname_vorname(Person *p1, Person *p2) {
	bool is_richtig = false;
    if(p1->get_gebdat().get_datum() < p2->get_gebdat().get_datum()){
    	is_richtig = true;
    }else if (p1->get_gebdat().get_datum() > p2->get_gebdat().get_datum()){
    	is_richtig = false;
    }
    else{
    	if (p1->get_name().get_nachname() < p2->get_name().get_nachname()) {
    		is_richtig = true;
		} else if (p1->get_name().get_nachname() > p2->get_name().get_nachname()) {
			is_richtig = false;
		} else {
			 if (p1->get_name().get_vorname() < p1->get_name().get_vorname()) {
			  is_richtig = true;
			 } else if (p1->get_name().get_vorname() > p1->get_name().get_vorname()) {
			  is_richtig = false;
			 } else {
				 is_richtig = true;
			 }
		}

    }

	return is_richtig;
}


#endif /* PERSON_CPP_ */
