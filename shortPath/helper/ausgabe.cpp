#include "ausgabe.h"
/**
 * Setzt verschiendene Schalter zu Steuerung und Formatierung der Ausgabe
 * @param format Formatierung die Vorgenommen werden soll
 **/
void setze_schalter(ios_base::fmtflags format) {
	if (format == cout.dec || format == cout.oct || format == cout.hex)
		cout.setf(format, ios_base::basefield);
	else if (format == cout.left || format == cout.right || format
			== cout.internal)
		cout.setf(format, ios_base::adjustfield);
	else if (format == cout.scientific || format == cout.fixed)
		cout.setf(format, ios_base::floatfield);
	else
		cout.setf(format);

}

/**
 * Setzt verschiendene Schalter zu Steuerung und Formatierung der Ausgabe
 * und schreibt eine Zahl auf den Bildschirm.
 * @param zahl Zahl die ausgegeben werden soll
 * @param format Formatierung die Vorgenommen werden soll
 * @param anzahl_formate Formatierung die vorgenommen werden soll
 **/
void schreibe_zahl(long zahl, ios_base::fmtflags format[], int anzahl_formate) {
	for (int i = 0; i < anzahl_formate; i++)
		setze_schalter(format[i]);
	cout << zahl;
	for (int i = 0; i < anzahl_formate; i++)
		cout.unsetf(format[i]);
}



void print_number_from_matrix_int(int number){
	cout << "| ";
	// ios_base::fmtflags format = cout.right;
	setze_schalter(cout.right)	;
	cout << number;
	cout << "\t\t";
	
}
void print_number_from_matrix_double(double number){
	cout << "| ";
	zeige_zahl(number, 4);
	cout << "\t";
}
/**
 * Setzt verschiendene Schalter zu Steuerung und Formatierung der Ausgabe
 * und schreibt eine Zahl auf den Bildschirm.
 * @param zahl Zahl die ausgegeben werden soll.
 * @param format Formatierung die vorgenommen werden soll.
 **/
void schreibe_zahl(long zahl, ios_base::fmtflags format) {
	ios_base::fmtflags format_array[] = { format };
	schreibe_zahl(zahl, format_array, 1);
}

/**
 * Setzt verschiendene Schalter zu Steuerung und Formatierung der Ausgabe.
 * und schreibt eine Zahl auf den Bildschirm.
 * @param zahl Zahl die ausgegeben werden soll.
 * @param feldbreite welche die Zahl haben soll.
 * @param format Formatierung die vorgenommen werden soll.
 * @param anzahl_formate Formatierung die vorgenommen werden soll.
 **/
void schreibe_zahl(long zahl, streamsize feldbreite, ios_base::fmtflags format[], int anzahl_formate) {
	streamsize alte_feldbreite = cout.width();
	cout.width(feldbreite);
	schreibe_zahl(zahl, format, anzahl_formate);
	cout.width(alte_feldbreite);
}

/**
 * Schreibt eine Zahl mit bestimmten Foramtierungen.
 * @param zahl Zahl die ausgegeben werden soll.
 * @param feldbreite Feldbreite mit dem der Wert ausgegeben werden soll.
 * @param format Formatierung die Vorgenommen werden soll.
 **/
void schreibe_zahl(long zahl, streamsize feldbreite, ios_base::fmtflags format) {
	ios_base::fmtflags format_array[] = { format };
	schreibe_zahl(zahl, feldbreite, format_array, 1);
}

/**
 * Setzt verschiendene Schalter zu Steuerung und Formatierung der Ausgabe.
 * und schreibt eine Zahl auf den Bildschirm.
 * @param zahl Zahl die ausgegeben werden soll.
 * @param feldbreite Feldbreite welche die Zahl haben soll.
 * @param fuellzeichen Zeichen mit dem die restliche Feldbreite aufgefuellt werden soll.
 * @param format Formatierung die vorgenommen werden soll.
 * @param anzahl_formate Formatierung die vorgenommen werden soll.
 **/
void schreibe_zahl(long zahl, streamsize feldbreite, char fuellzeichen, ios_base::fmtflags format[], int anzahl_formate) {
	char altes_fuellzeichen = cout.fill();
	cout.fill(fuellzeichen);
	schreibe_zahl(zahl, feldbreite, format, anzahl_formate);
	cout.fill(altes_fuellzeichen);
}

/**
 * Setzt verschiendene Schalter zu Steuerung und Formatierung der Ausgabe.
 * und schreibt eine Zahl auf den Bildschirm.
 * @param zahl Zahl die ausgegeben werden soll.
 * @param feldbreite Feldbreite welche die Zahl haben soll.
 * @param fuellzeichen Zeichen mit dem die restliche Feldbreite aufgefuellt werden soll.
 * @param format Formatierung die vorgenommen werden soll.
 **/
void schreibe_zahl(long zahl, streamsize feldbreite, char fuellzeichen,ios_base::fmtflags format) {
	ios_base::fmtflags format_array[] = { format };
	schreibe_zahl(zahl, feldbreite, fuellzeichen, format_array, 1);
}

/**
 * Setzt verschiendene Schalter zu Steuerung und Formatierung der Ausgabe
 * und schreibt eine Zahl auf den Bildschirm.
 * @param zahl Zahl die ausgegeben werden soll.
 * @param format Formatierung die vorgenommen werden soll.
 * @param anzahl_formate Formatierung die vorgenommen werden soll.
 **/
void schreibe_zahl(long double zahl, ios_base::fmtflags format[], int anzahl_formate) {
	for (int i = 0; i < anzahl_formate; i++)
		setze_schalter(format[i]);
	cout << zahl;
	for (int i = 0; i < anzahl_formate; i++)
		cout.unsetf(format[i]);
}

/**
 * Setzt verschiendene Schalter zu Steuerung und Formatierung der Ausgabe
 * und schreibt eine Zahl auf den Bildschirm.
 * @param zahl Zahl die ausgegeben werden soll.
 * @param format Formatierung die vorgenommen werden soll.
 **/
void schreibe_zahl(long double zahl, ios_base::fmtflags format) {
	ios_base::fmtflags format_array[] = { format };
	schreibe_zahl(zahl, format_array, 1);
}

/**
 * Setzt verschiendene Schalter zu Steuerung und Formatierung der Ausgabe
 * und schreibt eine Zahl auf den Bildschirm.
 * @param zahl Zahl die ausgegeben werden soll.
 * @param feldbreite Feldbreite welche die Zahl haben soll.
 * @param format Formatierung die vorgenommen werden soll.
 * @param anzahl_formate Formatierung die vorgenommen werden soll.
 **/
void schreibe_zahl(long double zahl, streamsize feldbreite, ios_base::fmtflags format[], int anzahl_formate) {
	streamsize alte_feldbreite = cout.width();
	cout.width(feldbreite);
	schreibe_zahl(zahl, format, anzahl_formate);
	cout.width(alte_feldbreite);
}

/**
 * Setzt verschiendene Schalter zu Steuerung und Formatierung der Ausgabe
 * und schreibt eine Gleitkommazahl auf den Bildschirm.
 * @param zahl Zahl die ausgegeben werden soll.
 * @param feldbreite Feldbreite welche die Zahl haben soll.
 * @param format Formatierung die vorgenommen werden soll.
 **/
void schreibe_zahl(long double zahl, streamsize feldbreite, ios_base::fmtflags format) {
	ios_base::fmtflags format_array[] = { format };
	schreibe_zahl(zahl, feldbreite, format_array, 1);
}

/**
 * Setzt verschiendene Schalter zu Steuerung und Formatierung der Ausgabe
 * und schreibt eine Gleitkommazahl auf den Bildschirm.
 * @param zahl Zahl die ausgegeben werden soll.
 * @param feldbreite Feldbreite welche die Zahl haben soll.
 * @param fuellzeichen Zeichen mit dem die restliche Feldbreite aufgefuellt werden soll.
 * @param format Formatierung die vorgenommen werden soll.
 * @param anzahl_formate Formatierung die vorgenommen werden soll.
 **/
void schreibe_zahl(long double zahl, streamsize feldbreite, char fuellzeichen, ios_base::fmtflags format[], int anzahl_formate) {
	char altes_fuellzeichen = cout.fill();
	cout.fill(fuellzeichen);
	schreibe_zahl(zahl, feldbreite, format, anzahl_formate);
	cout.fill(altes_fuellzeichen);
}

/**
 * Setzt verschiendene Schalter zu Steuerung und Formatierung der Ausgabe
 * und schreibt eine Gleitkommazahl auf den Bildschirm.
 * @param zahl Zahl die ausgegeben werden soll.
 * @param feldbreite Feldbreite welche die Zahl haben soll.
 * @param fuellzeichen Zeichen mit dem die restliche Feldbreite aufgefuellt werden soll.
 * @param format Formatierung die vorgenommen werden soll.
 * @param anzahl_formate Formatierung die vorgenommen werden soll.
 * @param praezision Praezision der Gleitkommazahl
 **/
void schreibe_zahl(long double zahl, streamsize feldbreite,char fuellzeichen,ios_base::fmtflags format[], int anzahl_formate, streamsize praezision){
	streamsize alte_praezision = cout.precision();
	cout.precision(praezision);
	schreibe_zahl(zahl, feldbreite, fuellzeichen, format, anzahl_formate);
	cout.precision(alte_praezision);
}
/**
 * Setzt verschiendene Schalter zu Steuerung und Formatierung der Ausgabe
 * und schreibt eine Gleitkommazahl auf den Bildschirm.
 * @param zahl Zahl die ausgegeben werden soll.
 * @param feldbreite Feldbreite welche die Zahl haben soll.
 * @param fuellzeichen Zeichen mit dem die restliche Feldbreite aufgefuellt werden soll.
 * @param format Formatierung die vorgenommen werden soll.
 * @param anzahl_formate Formatierung die vorgenommen werden soll.
 **/
void schreibe_zahl(double zahl, streamsize feldbreite, char fuellzeichen, ios_base::fmtflags format[], int anzahl_formate){
	schreibe_zahl( (long double) zahl, feldbreite, fuellzeichen, format, anzahl_formate);
}
/**
 * Setzt verschiendene Schalter zu Steuerung und Formatierung der Ausgabe
 * und schreibt eine Gleitkommazahl auf den Bildschirm.
 * @param zahl Zahl die ausgegeben werden soll.
 * @param feldbreite Feldbreite welche die Zahl haben soll.
 * @param fuellzeichen Zeichen mit dem die restliche Feldbreite aufgefuellt werden soll.
 * @param format Formatierung die vorgenommen werden soll.
 * @param anzahl_formate Formatierung die vorgenommen werden soll.
 **/
void schreibe_zahl(int zahl, streamsize feldbreite, char fuellzeichen, ios_base::fmtflags format[], int anzahl_formate){
	schreibe_zahl( (long) zahl, feldbreite, fuellzeichen, format, anzahl_formate);
}

/**
 * Setzt verschiendene Schalter zu Steuerung und Formatierung der Ausgabe
 * und schreibt eine Gleitkommazahl auf den Bildschirm.
 * @param zahl Zahl die ausgegeben werden soll.
 * @param feldbreite Feldbreite welche die Zahl haben soll.
 * @param fuellzeichen Zeichen mit dem die restliche Feldbreite aufgefuellt werden soll.
 * @param format Formatierung die vorgenommen werden soll.
 **/
void schreibe_zahl(long double zahl, streamsize feldbreite, char fuellzeichen, ios_base::fmtflags format) {
	ios_base::fmtflags format_array[] = { format };
	schreibe_zahl(zahl, feldbreite, fuellzeichen, format_array, 1);
}

/**
 * Setzt verschiendene Schalter zu Steuerung und Formatierung der Ausgabe
 * und schreibt eine Gleitkommazahl auf den Bildschirm.
 * @param praezision Praezision der Gleitkommazahl
 * @param zahl Zahl die ausgegeben werden soll.
 * @param feldbreite Feldbreite welche die Zahl haben soll.
 * @param format Formatierung die vorgenommen werden soll.
 * @param anzahl_formate Formatierung die vorgenommen werden soll.
 **/
void schreibe_zahl(streamsize praezision, long double zahl, streamsize feldbreite, ios_base::fmtflags format[], int anzahl_formate) {
	streamsize alte_praezision = cout.precision();
	cout.precision(praezision);
	schreibe_zahl(zahl, feldbreite, format, anzahl_formate);
	cout.precision(alte_praezision);
}

/**
 * Zeigt die Zahlen aus einem Bereich mit einem definierten abstand
 * und schreibt eine Gleitkommazahl auf den Bildschirm.
 * @param von Anfang des Bereiches.
 * @param bis Ende des Bereiches.
 * @param abstand Abstand in dem die Zahl ausgegeben werden soll.
 * @param praezision Praezision der Gleitkommazahl
 **/
void zeige_zahl_von_bis(long double von, long double bis, long double abstand, streamsize praezision) {
	for (; von <= bis; von += abstand)
		zeige_zahl(von, praezision);
}

/**
 * Dient der Ausgabe einer Gleitkommazahl mit entsprechender Praezision.
 * @param wert Wert der ausgegeben werden soll.
 * @param praezision Praezision die verwendet werden soll.
 **/
void zeige_zahl(double wert, streamsize praezision) {
	Formattyp dez_rechts[] = { cout.dec, cout.right };
	//char fuellzeichen = ' ';
	schreibe_zahl(praezision, static_cast<long double> (wert), praezision + 8, dez_rechts, 2);
}

/**
 * Macht einene Spaltenvorschub um die Uebergebene laenge.
 * @param feldbreite Feldbreite ganzzzahliger datentyp der einen Spaltenvorschub um den entsprechenden Wert macht
 **/
void spaltenvorschub(streamsize feldbreite) {
	cout.width(feldbreite);
	cout << "";
}

/**
 * Loescht den Bildschirminhalt der Konsole.
 **/
void loesche_bildschirm() {
	clrscr();
}
/**
 * Loescht den Bildschirm der Konsole und schreibt den Header des Programmes.
 */
void loesche_bildschirm_mit_header() {
	clrscr();
	header();
}
/**
 * Schreibt einen Header fuer das Programm.
 */
void header(){
	cout << "###############################################" <<endl;
	cout << "# Kuerzeste Wegeberechnung mit Multiprocessor #"<<endl;
	cout << "###############################################" <<endl;
	cout << endl;
}

/**
 * Setzt verschiendene Schalter zu Steuerung und Formatierung der Ausgabe
 * und schreibt einen Text auf den Bildschirm.
 * @param text Text der ausgegeben werden soll.
 * @param format Formatierung die vorgenommen werden soll.
 * @param anzahl_formate Formatierung die vorgenommen werden soll.
 **/
void schreibe_text(string text, ios_base::fmtflags format[], int anzahl_formate) {
	for (int i = 0; i < anzahl_formate; i++)
		setze_schalter(format[i]);
	cout << text;
	for (int i = 0; i < anzahl_formate; i++)
		cout.unsetf(format[i]);
}

/**
 * Setzt verschiendene Schalter zu Steuerung und Formatierung der Ausgabe
 * und schreibt einen Text auf den Bildschirm.
 * @param text Text der ausgegeben werden soll.
 * @param feldbreite Feldbreite welche die Zahl haben soll.
 * @param fuellzeichen Zeichen mit dem die restliche Feldbreite aufgefuellt werden soll.
 * @param format Formatierung die vorgenommen werden soll.
 **/
void schreibe_text(string text, streamsize feldbreite, char fuellzeichen, ios_base::fmtflags format) {
	ios_base::fmtflags format_array[] = { format };
	schreibe_text(text, feldbreite, fuellzeichen, format_array, 1);
}

/**
 * Setzt verschiendene Schalter zu Steuerung und Formatierung der Ausgabe
 * und schreibt einen Text auf den Bildschirm.
 * @param text Text der ausgegeben werden soll.
 * @param feldbreite Feldbreite welche die Zahl haben soll.
 **/
void schreibe_text(string text, streamsize feldbreite) {
	streamsize alte_feldbreite = cout.width();
	cout.width(feldbreite);
	cout << text;
	cout.width(alte_feldbreite);
}

/**
 * Setzt verschiendene Schalter zu Steuerung und Formatierung der Ausgabe
 * und schreibt einen Text auf den Bildschirm.
 * @param text Text der ausgegeben werden soll.
 * @param feldbreite Feldbreite welche die Zahl haben soll.
 * @param fuellzeichen Zeichen mit dem die restliche Feldbreite aufgefuellt werden soll.
 **/
void schreibe_text(string text, streamsize feldbreite, char fuellzeichen) {
	char altes_fuellzeichen = cout.fill();
	cout.fill(fuellzeichen);
	schreibe_text(text, feldbreite);
	cout.fill(altes_fuellzeichen);
}

/**
 * Setzt verschiendene Schalter zu Steuerung und Formatierung der Ausgabe
 * und schreibt einen Text auf den Bildschirm.
 * @param text Text der ausgegeben werden soll.
 * @param feldbreite Feldbreite welche die Zahl haben soll.
 * @param format Formatierung die vorgenommen werden soll.
 * @param anzahl_formate Formatierung die vorgenommen werden soll.
 **/
void schreibe_text(string text, streamsize feldbreite, ios_base::fmtflags format[], int anzahl_formate) {
	streamsize alte_feldbreite = cout.width();
	cout.width(feldbreite);
	schreibe_text(text, format, anzahl_formate);
	cout.width(alte_feldbreite);
}

/**
 * Setzt verschiendene Schalter zu Steuerung und Formatierung der Ausgabe
 * und schreibt einen Text auf den Bildschirm.
 * @param text Text der ausgegeben werden soll.
 * @param feldbreite Feldbreite welche die Zahl haben soll.
 * @param fuellzeichen Zeichen mit dem die restliche Feldbreite aufgefuellt werden soll.
 * @param format Formatierung die vorgenommen werden soll.
 * @param anzahl_formate Formatierung die vorgenommen werden soll.
 **/
void schreibe_text(string text, streamsize feldbreite, char fuellzeichen, ios_base::fmtflags format[], int anzahl_formate) {
	char altes_fuellzeichen = cout.fill();
	cout.fill(fuellzeichen);
	schreibe_text(text, feldbreite, format, anzahl_formate);
	cout.fill(altes_fuellzeichen);
}
/**
 * Haelt das Programm an nach druecken einer beliebigen Taste wird es fortgefuehrt.
 */
void wait(){
	string str;
	cout << "Druecken Sie Enter um fortzufahren ...";
	getline(cin,str);
}




