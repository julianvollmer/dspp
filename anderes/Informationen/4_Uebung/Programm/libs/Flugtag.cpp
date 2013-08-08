/*
 * Flugtag.cpp
 *
 *  Created on: 30.05.2010
 *      Author: julian
 */
#include "Flugtag.h"

/**
 * Standardkonstruktor fuer einen Flugtag.
 */
Flugtag::Flugtag(){
	init_flughaefen(1);
	flughafen_geringster_durchsatz_angekommen = flughaefen[0];
	flughafen_hoechster_durchsatz_abgeflogen = flughaefen[0];
	flughafen_geringster_durchsatz_angekommen = flughaefen[0];
	flughafen_hoechster_durchsatz_abgeflogen = flughaefen[0];
	anz_passagiere_ges = 0;
}

/**
 * Standartkonstruktor für einen Flugtag mit definierter Anzahl von Flughaefen
 * @param anz Anzahl der zu initialisierenden flughaefen
 */
Flugtag::Flugtag(int anz){
	init_flughaefen(anz);
	flughafen_geringster_durchsatz_angekommen = flughaefen[0];
	flughafen_hoechster_durchsatz_abgeflogen = flughaefen[0];
	flughafen_geringster_durchsatz_angekommen = flughaefen[0];
	flughafen_hoechster_durchsatz_abgeflogen = flughaefen[0];
	this->anz_tage = 1;
	anz_passagiere_ges = 0;
}

/**
 * Setzt den Flug mit der geringsten Auslastung
 * @param flug setzt den Parameter flug_geringste_auslastung
 */
void Flugtag::set_flug_geringste_auslastung(Flug flug){
	this->flug_geringste_auslastung = flug;
}

/**
 * Setzt den Flug mit der hoechsten Auslastung
 * @param flug setzt den Parameter flug_hoechste_auslastung
 */
void Flugtag::set_flug_hoechste_auslastung(Flug flug){
	this->flug_hoechste_auslastung = flug;
}

/**
 * @param flughafen Setzt den Flughafen flughafen_geringster_durchsatz_angekommen
 */
void Flugtag::set_flughafen_geringster_durchsatz_angekommen(Flughafen flughafen){
	this->flughafen_geringster_durchsatz_angekommen  = flughafen;
}

/**
 * @param flughafen Setzt den Flughafen flughafen_geringster_durchsatz_abgeflogen
 */
void Flugtag::set_flughafen_geringster_durchsatz_abgeflogen(Flughafen flughafen){
	this->flughafen_geringster_durchsatz_abgeflogen  = flughafen;
}
/**
 * @param flughafen Setzt den Flughafen flughafen_hoechster_durchsatz_angekommen
 */
void Flugtag::set_flughafen_hoechster_durchsatz_angekommen(Flughafen flughafen){
	this->flughafen_hoechster_durchsatz_angekommen = flughafen;
}

/**
 * Dient des setzten des Flughafens, der den hoechsten Durchsatz hat.
 * @param flughafen setzt flughafen_hoechster_durchsatz_abgeflogen
 */
void Flugtag::set_flughafen_hoechster_durchsatz_abgeflogen(Flughafen flughafen){
	this->flughafen_hoechster_durchsatz_abgeflogen = flughafen;
}

/**
 * @param die_passagiere Setzt die Anzahl der  Passagiere eines Flugtages.
 */
void Flugtag::set_anz_passagiere_ges(int die_passagiere){
	this->anz_passagiere_ges = die_passagiere;
}

/**
 * @return Gibt den Flug mit der geringsten
 */
Flug Flugtag::get_flug_geringste_auslastung(){
	return this->flug_geringste_auslastung;
}

/**
 * @return Gibt den Flug mit der hoechsten Auslastung zurueck
 */
Flug Flugtag::get_flug_hoechste_auslastung(){
	return this->flug_hoechste_auslastung;
}

/**
 * @return Gibt den Flughafen mit dem geringsten Durchsatz von abgeflogenen Passagieren zurueck.
 */
Flughafen Flugtag::get_flughafen_geringster_durchsatz_abgeflogen(){
	return this->flughafen_geringster_durchsatz_abgeflogen;
}

/**
 * @return Gibt den Flughafen mit dem hoechsten Durchsatz von abgeflogenen Passagieren zurueck.
 */
Flughafen Flugtag::get_flughafen_hoechster_durchsatz_abgeflogen(){
	return this->flughafen_hoechster_durchsatz_abgeflogen;
}

/**
 * @return Gibt den Flughafen  mit den wenigsten angekommenen Passagieren zurueck.
 */
Flughafen Flugtag::get_flughafen_geringster_durchsatz_angekommen(){
	return this->flughafen_geringster_durchsatz_abgeflogen;
}
/**
 * Gibt ein Flughafen zurueck.
 */
Flughafen Flugtag::get_flughafen_hoechster_durchsatz_angekommen(){
	return this->flughafen_hoechster_durchsatz_abgeflogen;
}

/**
 * Gibt ein Vector vom Typ Flughafen zurueck.
 */
vector<Flughafen> Flugtag::get_flughaefen(){
	return this->flughaefen;
}


/**
 * Simuliert einen Flugtag und setzt die Flughaefen mit den geringsten
 * Durchsaetzen von angekommen, abgeflogenen,
 * hoechsten angekommen und abgeflogenen Durchsaetzen.
 * Sobald der Flugtag simuliert und ausgegeben ist, wird er Zurueckgesetz.
 */
void Flugtag::simuliere_fluege() {
	do {
		int anz = liefere_ganze_zufallszahl(5000,7000);
		for(int i = 0; i < anz; i++) {
			this->fliegen();
		}
		set_flughafen_geringster_durchsatz_angekommen(hole_flughafen_geringster_durchsatz_angekommen());
		set_flughafen_hoechster_durchsatz_angekommen(hole_flughafen_hoechster_durchsatz_angekommen());
		set_flughafen_geringster_durchsatz_abgeflogen(hole_flughafen_geringster_durchsatz_abgeflogen());
		set_flughafen_hoechster_durchsatz_abgeflogen(hole_flughafen_hoechster_durchsatz_abgeflogen());
		loesche_bildschirm_mit_header();
		this->zeige_fluege();
		this->flugtag_zuruecksetzen();
		this->anz_tage++;
	}while (erfasse_int(0,1,"0 zum beeneden 1 um einen weiteren Tag zu simulieren") ==1 );
}
/**
 * Bestimmt die Auslastung eines Flugtages.
 */

double Flugtag::get_auslastung(){
	double auslastung = 0.0;
	for(unsigned int i = 0; i < this->fluege.size();i++){
		auslastung += this->fluege[i].get_auslastung();
	}
	return (auslastung / this->fluege.size());
}
/**
 * Setzt alle Werte eines Flugtages zurueck außer die vergangenen Tage.
 */
void Flugtag::flugtag_zuruecksetzen(){
	this->anz_passagiere_ges = 0;
	this->fluege.erase(fluege.begin(),fluege.end());
	this->flug_geringste_auslastung.set_anz_passagiere(0);
	this->flug_geringste_auslastung.set_auslastung(50.0);
	this->flug_hoechste_auslastung.set_anz_passagiere(0);
	this->flug_hoechste_auslastung.set_auslastung(0.0);
	this->flughafen_geringster_durchsatz_abgeflogen.set_durchsatz_abgeflogen(0);
	this->flughafen_geringster_durchsatz_abgeflogen.set_durchsatz_angekommen(0);
	this->flughafen_geringster_durchsatz_angekommen.set_durchsatz_abgeflogen(0);
	this->flughafen_geringster_durchsatz_angekommen.set_durchsatz_angekommen(0);
	for(unsigned int i = 0; i < flughaefen.size(); i++ ){
		flughaefen[i].set_durchsatz_abgeflogen(0);
		flughaefen[i].set_durchsatz_angekommen(0);
	}
}
/**
 * Sucht einen Zielflughafen welcher nicht der Start ist
 * @param der_start Name des Startflughafen
 */

int Flugtag::suche_ziel(string der_start){
	int auswahl_flughafen = liefere_ganze_zufallszahl(0, (flughaefen.size()-1));
	while((unsigned int)flughaefen[auswahl_flughafen].get_max_flieger() > flughaefen[auswahl_flughafen].get_flieger().size() && flughaefen[auswahl_flughafen].get_name() == der_start ){
		auswahl_flughafen = liefere_ganze_zufallszahl(0, (flughaefen.size()-1));
	}
	return auswahl_flughafen;
}

/**
 * Simuliert die durchzufuehrenden Fluege,
 * prueft ob ein Flugzeug am Start vorhanden ist,
 * erzeugt zufaellig die Passagiere die mitfliegen,
 * erhoeht den Durchsatz der Flughaefen und
 * sucht einen Zielflughfen.
 */

void Flugtag::fliegen(){
	int auswahl_flughafen = liefere_ganze_zufallszahl(0, (flughaefen.size() - 1));
	int auswahl_flieger = liefere_ganze_zufallszahl(0, (flughaefen[auswahl_flughafen].get_flieger().size() - 1) );
	while(flughaefen[auswahl_flughafen].get_flieger().size() <= 0){
		auswahl_flughafen = liefere_ganze_zufallszahl(0, (flughaefen.size() - 1));
		auswahl_flieger = liefere_ganze_zufallszahl(0, (flughaefen[auswahl_flughafen].get_flieger().size() - 1));
	}
	int passagiere = liefere_ganze_zufallszahl(0, flughaefen[auswahl_flughafen].get_flieger()[auswahl_flieger].get_max_passagiere());
	this->anz_passagiere_ges += passagiere;
	Flug f(flughaefen[auswahl_flughafen].get_flieger()[auswahl_flieger]);
	f.set_anz_passagiere(passagiere);
	f.set_start(flughaefen[auswahl_flughafen].get_name());
	int ziel = suche_ziel( flughaefen[auswahl_flughafen].get_name() );
	flughaefen[ziel].erhoehe_durchsatz_angekommen(passagiere);

	flughaefen[auswahl_flughafen].erhoehe_durchsatz_abgefloggen(passagiere);
	flughaefen[ziel].platziere_flugezeug(flughaefen[auswahl_flughafen].get_flieger()[auswahl_flieger]);
	f.set_ziel(flughaefen[ziel].get_name());
	if(this->get_flug_geringste_auslastung().get_auslastung() > f.get_auslastung()){
		this->set_flug_geringste_auslastung(f);
	}
	if(this->get_flug_hoechste_auslastung().get_auslastung() < f.get_auslastung()){
		this->set_flug_hoechste_auslastung(f);
	}
	this->fluege.push_back(f);
	flughaefen[auswahl_flughafen].loesche_flugezeug(auswahl_flieger);

}
/**
 * Sucht aus dem Vector vom Typ Flughafen den mit dem geringsten Durchsatz von angekommen Passagieren
 */
Flughafen Flugtag::hole_flughafen_hoechster_durchsatz_angekommen(){
	Flughafen f;
	for(unsigned int i = 0; i < flughaefen.size(); i++ ){
		if(f.get_durchsatz_angekommen() < flughaefen[i].get_durchsatz_angekommen())
			f = flughaefen[i];
	}
	return f;
}
/**
 * Sucht aus dem Vector vom Typ Flughafen den mit dem geringsten Durchsatz von angekommen Passagieren
 */
Flughafen Flugtag::hole_flughafen_geringster_durchsatz_angekommen(){
	Flughafen f = flughaefen[0];
	for(unsigned int i = 0; i < flughaefen.size(); i++ ){
		if(f.get_durchsatz_angekommen() > flughaefen[i].get_durchsatz_angekommen())
			f = flughaefen[i];
	}
	return f;
}

/**
 * Sucht aus dem Vector vom Typ Flughafen den mit dem hoechsten Durchsatz von abgeflogenen Passagieren
 */
Flughafen Flugtag::hole_flughafen_hoechster_durchsatz_abgeflogen(){
	Flughafen f;
	for(unsigned int i = 0; i < flughaefen.size(); i++ ){
		if(f.get_durchsatz_abgeflogen() < flughaefen[i].get_durchsatz_abgeflogen())
			f = flughaefen[i];
	}
	return f;
}

/**
 * Sucht aus dem Vector vom Typ Flughafen, den mit dem geringsten Durchsatz von abgeflogenen Passagieren.
 */
Flughafen Flugtag::hole_flughafen_geringster_durchsatz_abgeflogen(){
	Flughafen f = flughaefen[0];
	for(unsigned int i = 0; i < flughaefen.size(); i++ ){
		if(f.get_durchsatz_abgeflogen() > flughaefen[i].get_durchsatz_abgeflogen())
			f = flughaefen[i];
	}
	return f;
}

/**
 * Initilisiert Flughaefen
 * @param anz Anzahl der Flughaefen die initialisiert werden sollen.
 */
void Flugtag::init_flughaefen(int anz){
	for(int i = 0; i < anz ; i++){
		Flughafen f;
		this->flughaefen.push_back(f);
	}
}

/**
 * Gibt Informationen ueber einen Flug in der folgenden Darstellung aus
 * ---- Tag 29 ----
 * Fluege:6864
 * Auslastung
 * total: 49.312 %
 * max: VAN -> VNM, 33 von 33 Prozent 100
 * min: VAN -> OIM, 0 von 33 Prozent 0
 * Passagiere abgeflogen
 *           total..........:468328
 *           max............:29689
 *           min............:12616
 *
 *
 * Passagiere angekommen
 *           total..........:468328
 *           max............:25812
 *           min............:20340
 */

void Flugtag::zeige_fluege(){
	streamsize lanege = 15;
	cout << "---- Tag "<<this->anz_tage<<" ----"<<endl <<endl ;
	cout << "Fluege:" << fluege.size()<<endl;
	cout << "Auslastung"<<endl;
	cout << "total: " << get_auslastung() << " %" <<endl;
	cout << "max: " << flug_hoechste_auslastung.get_start() <<" -> " << flug_hoechste_auslastung.get_ziel() << ", ";
	cout << flug_hoechste_auslastung.get_anz_passagiere() << " von "  << flug_hoechste_auslastung.get_flieger().get_max_passagiere() << " Prozent " << flug_hoechste_auslastung.get_auslastung() <<endl;
	cout << "min: " << flug_geringste_auslastung.get_start() <<" -> " << flug_geringste_auslastung.get_ziel() << ", ";
	cout << flug_geringste_auslastung.get_anz_passagiere() << " von "  << flug_geringste_auslastung.get_flieger().get_max_passagiere() << " Prozent " << flug_geringste_auslastung.get_auslastung() <<endl;
	cout << "Passagiere abgeflogen" << endl;

	spaltenvorschub(10);
	schreibe_text("total",lanege,'.',cout.left);
	cout <<":";
	cout << anz_passagiere_ges<< endl;

	spaltenvorschub(10);
	schreibe_text("max",lanege,'.',cout.left);
	cout <<":";
	cout << flughafen_hoechster_durchsatz_abgeflogen.get_durchsatz_abgeflogen() << endl;

	spaltenvorschub(10);
	schreibe_text("min",lanege,'.',cout.left);
	cout <<":";
	cout << flughafen_geringster_durchsatz_abgeflogen.get_durchsatz_abgeflogen() << endl<< endl<< endl;

	cout << "Passagiere angekommen" << endl;

	spaltenvorschub(10);
	schreibe_text("total",lanege,'.',cout.left);
	cout <<":";
	cout << anz_passagiere_ges<< endl;

	spaltenvorschub(10);
	schreibe_text("max",lanege,'.',cout.left);
	cout <<":";
	cout << flughafen_hoechster_durchsatz_angekommen.get_durchsatz_angekommen() << endl;

	spaltenvorschub(10);
	schreibe_text("min",lanege,'.',cout.left);
	cout <<":";
	cout << flughafen_geringster_durchsatz_angekommen.get_durchsatz_angekommen() << endl<< endl<< endl;
}







