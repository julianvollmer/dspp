/*
 * Name.cpp
 *
 *  Created on: 12.06.2010
 *      Author: jule
 */

#ifndef NAME_CPP_
#define NAME_CPP_
#include "Name.h"
/**
 *
 */
const string def_vornamen_w[] = {"Andrea", "Angelika", "Anja", "Anke", "Anna", "Anne", "Annett", "Antje", "Barbara", "Brgit", "Brigitte", "Christin", "Christina", "Christine", "Claudia", "Daniela", "Diana", "Doreen", "Franziska", "Gabriele", "Heike", "Ines", "Jana", "Janina", "Jennifer", "Jessica", "Jessika", "Julia", "Juliane", "Karin", "Karolin", "Katharina", "Kathrin", "Katrin", "Katja", "Kerstin", "Klaudia", "Kristin", "Laura", "Lea", "Lena", "Lisa", "Mandy", "Manuela", "Maria", "Marie", "Marina", "Martina", "Melanie", "Monika", "Nadine", "Nicole", "Petra", "Sabine", "Sabrina", "Sandra", "Sara", "Sarah", "Silke", "Simone", "Sophia", "Sophie", "Stefanie", "Stephanie", "Susanne", "Tanja", "Ulrike", "Ursula", "Uta", "Ute", "Vanessa", "Yvonne ", "Anna", "Anneliese", "Berta", "Bertha", "Charlotte", "Clara", "Klara", "Edith", "Elfriede", "Elisabeth", "Ella", "Else", "Emma", "Erika", "Erna", "Frieda", "Frida", "Gerda", "Gertrud", "Gisela", "Hedwig", "Helene", "Helga", "Herta", "Hertha", "Hildegard", "Ida", "Ilse", "Ingeborg", "Irmgard", "Johanna", "Kaete", "Kaethe", "Lieselotte", "Liselotte", "Louise", "Luise", "Margarethe", "Margarete", "Margot", "Maria", "Marie", "Marta", "Martha", "Ruth", "Ursula", "Waltraud", "Waltraut"};
const string def_vornamen_m[] = {"Alexander", "Andreas", "Benjamin", "Bernd", "Christian", "Daniel", "David", "Dennis", "Dieter", "Dirk", "Dominik", "Eric", "Erik", "Felix", "Florian", "Frank", "Jan", "Jens", "Jonas", "Joerg", "Juergen", "Kevin", "Klaus", "Kristian ", "Leon", "Lukas", "Marcel", "Marco", "Marko", "Mario", "Markus", "Martin", "Mathias", "Matthias", "Max", "Maximilian", "Michael", "Mike", "Maik", "Niklas", "Patrick", "Paul", "Peter", "Philipp", "Phillipp", "Ralf", "Ralph", "Rene", "Robert", "Sebastian", "Stefan", "Stephan", "Steffen", "Sven", "Swen", "Thomas", "Thorsten", "Torsten", "Tim", "Tobias", "Tom", "Ulrich", "Uwe", "Wolfgang", "Alfred", "Arthur", "Artur", "Bruno", "Carl", "Claus", "Curt", "Erich", "Ernst", "Franz", "Friedrich", "Fritz", "Georg", "Gerhard", "Guenther", "Guenter", "Hans", "Harry", "Heinz", "Helmut", "Hellmuth", "HerbertHermann", "Horst", "Joachim", "Karl", "Karlheinz", "Karl-Heinz", "Klaus", "Kurt ", "Manfred", "Max", "Otto", "Paul", "Richard", "Rudolf", "Walter", "Werner", "Wilhelm", "Willi", "Willy", "Wolfgang"};
const string def_nachnamen[] = {"Mueller", "Schmidt", "Schneider", "Fischer", "Weber", "Meyer", "Wagner", "Becker", "Schulz", "Hoffmann", "Schaefer", "Koch", "Bauer", "Richter", "Klein", "Wolf", "Schroeder", "Neumann", "Schwarz", "Zimmermann", "Braun", "Krueger", "Hofmann", "Hartmann", "Lange", "Schmitt", "Werner", "Schmitz", "Krause", "Meier", "Lehmann", "Schmid", "Schulze", "Maier", "Koehler", "Herrmann", "Koenig", "Walter", "Mayer", "Huber", "Kaiser", "Fuchs", "Peters", "Lang", "Scholz", "Moeller", "Weiss", "Jung", "Hahn", "Schubert", "Vogel", "Friedrich", "Keller", "Guenther", "Frank", "Berger", "Winkler", "Roth", "Beck", "Lorenz", "Baumann", "Franke", "Albrecht", "Schuster", "Simon", "Ludwig", "Boehm", "Winter", "Kraus", "Martin", "Schumacher", "Kraemer", "Vogt", "Stein", "Jaeger", "Otto", "Sommer", "Gross", "Seidel", "Siegfried", "Sieghart", "Heinrich", "Brandt", "Haas", "Schreiber", "Graf", "Schulte", "Dietrich", "Ziegler", "Kuhn", "Kuehn", "Pohl", "Engel", "Horn", "Busch", "Bergmann", "Thomas", "Voigt", "Sauer", "Arnold", "Wolff", "Pfeiffer"};

const int anz_vornamen_w = sizeof(def_vornamen_w) / sizeof(def_vornamen_w[0]);
const int anz_vornamen_m = sizeof(def_vornamen_m) / sizeof(def_vornamen_m[0]);
const int anz_nachnamen = sizeof(def_nachnamen) / sizeof(def_nachnamen[0]);
/**
 * Erzeugt einen Namen zufaellig.
 */
Name::Name(){
	if ((zufallszahl_int(100) % 2) == 0 ) {
		vorname = def_vornamen_w[liefere_ganze_zufallszahl(0, anz_vornamen_w - 1)];
		geschlecht = 'w';
	}
	else{
		vorname = def_vornamen_m[liefere_ganze_zufallszahl(0, anz_vornamen_m - 1)];
		geschlecht = 'm';
	}

	nachname = def_nachnamen[liefere_ganze_zufallszahl(0, anz_nachnamen - 1)];
	geburtsname = nachname;
}

Name::~Name(){

}

/**
 * @return Gibt den Vornamen zurueck
 */
string Name::get_vorname(){
	return this->vorname;
}
/**
 * @return Gibt den Nachnamen zurueck.
 */
string Name::get_nachname(){
	return this->nachname;
}
/**
 * Gibt den Geburtsnamen zurueck
 */
string Name::get_geburtsname(){
	return this->geburtsname;
}
/**
 * @return Gibt den Title zurueck
 */
string Name::get_title(){
	return this->title;
}
/**
 * @return Gibt das Geschlecht zurueck.
 */
char Name::get_geschlecht(){
	return this->geschlecht;
}

/**
 * Setzt den Vornamen.
 * @param der_vorname Vorname der gesetzt werden soll.
 */
void Name::set_vorname(string der_vorname){
	vorname = der_vorname;
}
/**
 * Setzt den Nachnamen
 * @param der_nachname Nachname der gesetzt werden soll.
 */
void Name::set_nachname(string der_nachnam){
	nachname = der_nachnam;
}
/**
 * Setzt den Geburtsnamen zurueck.
 * @param der_geburtsname Geburtsname die gesetzt werden soll.
 */
void Name::set_geburtsname(string der_geburtsname){
	geburtsname = der_geburtsname;
}

/**
 * Setzt den Title.
 * @param der_title Titel der gesetzt werden soll.
 */
void Name::set_title(string der_title){
	title = der_title;
}
/**
 * Erfasst einen Vornamen.
 */
void Name::erfasse_vorname(){
	cout << "Bitte geben Sie den Vornamen ein: ";
	getline(cin,this->vorname);

}
/**
 * Erfasst einen Nachnamen.
 */
void Name::erfasse_nachname(){
	cout << "Bitte geben Sie den Nachnamen ein: ";
	getline (cin,this->nachname);
}
/**
 * Erfasst einen Title.
 */
void Name::erfasse_title(){
	cout << "Bitte geben Sie den Title ein: ";
	getline (cin,this->title);
}
/**
 * Erfasst das Geschlecht.
 */
void Name::erfasse_geschlecht(){
	do{
		cout << "Bitte geben Sie m oder w für das Geschlecht ein: ";
		cin >> geschlecht;
	}while (geschlecht != 'm' && geschlecht != 'w');
}

/**
 * Erfasst einen Geburtsnamen.
 */
void Name::erfasse_geburtsname(){
	cout << "Bitte geben Sie den Geburtsnamen ein: ";
	cin >> geburtsname;
}
/**
 * Erfasst einen Kompletten Namen, mit Nachname, Vorname, Title, Geschlecht und Geburtsname.
 */
void Name::erfasse_name(){
	erfasse_vorname();
	erfasse_nachname();
	erfasse_title();
	erfasse_geschlecht();
	erfasse_geburtsname();
}
#endif /* NAME_CPP_ */
