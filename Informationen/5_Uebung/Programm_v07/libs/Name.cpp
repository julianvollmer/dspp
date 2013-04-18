/*
 * Name.cpp
 *
 *  Created on: 12.06.2010
 *      Author: jule
 */

#ifndef NAME_CPP_
#define NAME_CPP_
#include "Name.h"

 string def_vornamen_w[] = {"Andrea", "Angelika", "Anja", "Anke", "Anna", "Anne", "Annett", "Antje", "Barbara", "Brgit", "Brigitte", "Christin", "Christina", "Christine", "Claudia", "Daniela", "Diana", "Doreen", "Franziska", "Gabriele", "Heike", "Ines", "Jana", "Janina", "Jennifer", "Jessica", "Jessika", "Julia", "Juliane", "Karin", "Karolin", "Katharina", "Kathrin", "Katrin", "Katja", "Kerstin", "Klaudia", "Kristin", "Laura", "Lea", "Lena", "Lisa", "Mandy", "Manuela", "Maria", "Marie", "Marina", "Martina", "Melanie", "Monika", "Nadine", "Nicole", "Petra", "Sabine", "Sabrina", "Sandra", "Sara", "Sarah", "Silke", "Simone", "Sophia", "Sophie", "Stefanie", "Stephanie", "Susanne", "Tanja", "Ulrike", "Ursula", "Uta", "Ute", "Vanessa", "Yvonne ", "Anna", "Anneliese", "Berta", "Bertha", "Charlotte", "Clara", "Klara", "Edith", "Elfriede", "Elisabeth", "Ella", "Else", "Emma", "Erika", "Erna", "Frieda", "Frida", "Gerda", "Gertrud", "Gisela", "Hedwig", "Helene", "Helga", "Herta", "Hertha", "Hildegard", "Ida", "Ilse", "Ingeborg", "Irmgard", "Johanna", "Kaete", "Kaethe", "Lieselotte", "Liselotte", "Louise", "Luise", "Margarethe", "Margarete", "Margot", "Maria", "Marie", "Marta", "Martha", "Ruth", "Ursula", "Waltraud", "Waltraut"};
 string def_vornamen_m[] = {"Alexander", "Andreas", "Benjamin", "Bernd", "Christian", "Daniel", "David", "Dennis", "Dieter", "Dirk", "Dominik", "Eric", "Erik", "Felix", "Florian", "Frank", "Jan", "Jens", "Jonas", "Joerg", "Juergen", "Kevin", "Klaus", "Kristian ", "Leon", "Lukas", "Marcel", "Marco", "Marko", "Mario", "Markus", "Martin", "Mathias", "Matthias", "Max", "Maximilian", "Michael", "Mike", "Maik", "Niklas", "Patrick", "Paul", "Peter", "Philipp", "Phillipp", "Ralf", "Ralph", "Rene", "Robert", "Sebastian", "Stefan", "Stephan", "Steffen", "Sven", "Swen", "Thomas", "Thorsten", "Torsten", "Tim", "Tobias", "Tom", "Ulrich", "Uwe", "Wolfgang", "Alfred", "Arthur", "Artur", "Bruno", "Carl", "Claus", "Curt", "Erich", "Ernst", "Franz", "Friedrich", "Fritz", "Georg", "Gerhard", "Guenther", "Guenter", "Hans", "Harry", "Heinz", "Helmut", "Hellmuth", "HerbertHermann", "Horst", "Joachim", "Karl", "Karlheinz", "Karl-Heinz", "Klaus", "Kurt ", "Manfred", "Max", "Otto", "Paul", "Richard", "Rudolf", "Walter", "Werner", "Wilhelm", "Willi", "Willy", "Wolfgang"};
 string def_nachnamen[] = {"Mueller", "Schmidt", "Schneider", "Fischer", "Weber", "Meyer", "Wagner", "Becker", "Schulz", "Hoffmann", "Schaefer", "Koch", "Bauer", "Richter", "Klein", "Wolf", "Schroeder", "Neumann", "Schwarz", "Zimmermann", "Braun", "Krueger", "Hofmann", "Hartmann", "Lange", "Schmitt", "Werner", "Schmitz", "Krause", "Meier", "Lehmann", "Schmid", "Schulze", "Maier", "Koehler", "Herrmann", "Koenig", "Walter", "Mayer", "Huber", "Kaiser", "Fuchs", "Peters", "Lang", "Scholz", "Moeller", "Weiss", "Jung", "Hahn", "Schubert", "Vogel", "Friedrich", "Keller", "Guenther", "Frank", "Berger", "Winkler", "Roth", "Beck", "Lorenz", "Baumann", "Franke", "Albrecht", "Schuster", "Simon", "Ludwig", "Boehm", "Winter", "Kraus", "Martin", "Schumacher", "Kraemer", "Vogt", "Stein", "Jaeger", "Otto", "Sommer", "Gross", "Seidel", "Siegfried", "Sieghart", "Heinrich", "Brandt", "Haas", "Schreiber", "Graf", "Schulte", "Dietrich", "Ziegler", "Kuhn", "Kuehn", "Pohl", "Engel", "Horn", "Busch", "Bergmann", "Thomas", "Voigt", "Sauer", "Arnold", "Wolff", "Pfeiffer"};

 int anz_vornamen_w = sizeof(def_vornamen_w) / sizeof(def_vornamen_w[0]);
 int anz_vornamen_m = sizeof(def_vornamen_m) / sizeof(def_vornamen_m[0]);
 int anz_nachnamen = sizeof(def_nachnamen) / sizeof(def_nachnamen[0]);

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


string Name::get_vorname(){
	return this->vorname;
}

string Name::get_nachname(){
	return this->nachname;
}

string Name::get_geburtsname(){
	return this->geburtsname;
}

string Name::get_title(){
	return this->title;
}

char Name::get_geschlecht(){
	return this->geschlecht;
}

void Name::erfasse_vorname(){
	cout << "Bitte geben Sie den Vornamen ein: ";
	cin>>vorname;
}

void Name::erfasse_nachname(){
	cout << "Bitte geben Sie den Nachnamen ein: ";
	cin >> nachname;
}

void Name::erfasse_title(){
	cout << "Bitte geben Sie den Title ein: ";
	cin >> title;
}
void Name::erfasse_geschlecht(){
	do{
		cout << "Bitte geben Sie m oder w für das Geschlecht ein: ";
		cin >> geschlecht;
	}while (geschlecht != 'm' && geschlecht != 'w');
}

void Name::erfasse_geburtsname(){
	cout << "Bitte geben Sie den Geburtsnamen ein: ";
	cin >> geburtsname;
}

void Name::erfasse_name(){
	erfasse_vorname();
	erfasse_nachname();
	erfasse_title();
	erfasse_geschlecht();
	erfasse_geburtsname();
}
#endif /* NAME_CPP_ */
