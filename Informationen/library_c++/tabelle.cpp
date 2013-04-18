#include "tabelle.h"

/**
 * Dient der Ausgabe des Hauptmenues.
 **/
void menu_ausgabe() {
	clrscr();
	int auswahl = 0;
	string menu[] = { "cos", "sin", "tan", "acos", "asin", "atan", "exp", "log", "log10", "pow10", "sqrt", "Beenden" };
	int laenge = sizeof(menu) / sizeof(menu[0]);
	cout << "Bitte waehlen Sie eine der Folgenden Funktionen" << endl;
	do {
		for (int i = 0; i < laenge; i++) {
			cout << endl << "(" << i + 1 << ")" << menu[i];
		}
		cout << endl;
		auswahl = erfasse_daten();
	} while (auswahl != laenge);
}

/**
 * Erfasst die beötigten Daten mit denen das Programm die Berechnung durchführen soll
 * @return Menuepunkt der aus dem Hauptmenue ausgewaehlt wurde.
 **/
int erfasse_daten() {
	int auswahl = erfasse_int(1, 12);
	if (auswahl != 12) {
		double start = erfasse_double("Bitte geben Sie den Wert ein an dem die Funktion beginnen soll:\t", 1, 20);
		double ende = erfasse_double("Bitte geben Sie den Wert ein an dem die Funktion enden soll:\t", 1, 20);
		streamsize praezision = static_cast<streamsize> (erfasse_long(1, 20, "Bitte geben Sie den Praezision ein den die Werte haben sollen:\t"));
		zeige_tabelle(auswahl, start, ende, praezision);
	}
	return auswahl;
}
/**
 * Gibt die Tabelle in der vorgegebenen Grundstruktur aus
 * @param auswahl 	Auswahl derfeldbreite Funktion aus dem Hauptmenu.
 * @param start  	Startwert, mit dem das Programm den ersten Wert berechnen soll.
 * @param ende  	Endwert, bis zu welchem gerechent werden soll.
 **/
void zeige_tabelle(int auswahl, double start, double ende, streamsize praezision) {
	clrscr();
	funcp funktionen[] = { cos, sin, tan, acos, asin, atan, exp, log, log10, pow10, sqrt };
	string funktionsname[] = { "cos", "sin", "tan", "acos", "asin", "atan", "exp", "log", "log10", "pow10", "sqrt" };
	cout << "Funktion: " << funktionsname[auswahl - 1] << " x" << endl;
	int zaehler = 0;
	spaltenvorschub(praezision + 8);
	zeige_zahl_von_bis(0, 9, 1, praezision);
	for (double i = start; i < ende; i += 0.01) {

		zaehler = zaehler % 10;
		if (zaehler == 0) {
			cout << endl;
			zeige_zahl(i, praezision);
		}
		zeige_zahl(funktionen[auswahl - 1], i, praezision);
		zaehler++;
	}
	cout << endl;

}

/**
 * Gibt die Tabelle in der vorgegebenen Grundstruktur aus
 * @param auswahl 	Auswahl der Funktion aus dem Hauptmenu.
 * @param start  	Startwert, mit dem das Programm den ersten Wert berechnen soll.
 * @param ende  	Endwert, bis zu welchem gerechent werden soll.
 **/
void zeige_zahl(funcp func, double wert, streamsize praezision) {
	zeige_zahl(func(wert), praezision);
}

