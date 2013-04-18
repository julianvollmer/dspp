/*
 * Flugtag.h
 *
 *  Created on: 30.05.2010
 *      Author: julian
 */

#ifndef FLUGTAG_H_
#define FLUGTAG_H_

#include <iostream>
#include <vector>
using namespace std;

#include "Flughafen.h"
#include "Flug.h"
#include "Flugzeug.h"
#include "eingabe.h"
#include "ausgabe.h"

class Flugtag{
	private:

		Flug flug_geringste_auslastung;
		Flug flug_hoechste_auslastung;
		Flughafen flughafen_geringster_durchsatz_angekommen;
		Flughafen flughafen_geringster_durchsatz_abgeflogen;
		Flughafen flughafen_hoechster_durchsatz_abgeflogen;
		Flughafen flughafen_hoechster_durchsatz_angekommen;
		vector<Flug> fluege;
		vector<Flughafen> flughaefen;
		int anz_passagiere_ges;
		void init_flughaefen(int anz);
		int anz_tage;
		int suche_ziel(string der_start);

		Flughafen hole_flughafen_hoechster_durchsatz_angekommen();
		Flughafen hole_flughafen_geringster_durchsatz_angekommen();
		Flughafen hole_flughafen_hoechster_durchsatz_abgeflogen();
		Flughafen hole_flughafen_geringster_durchsatz_abgeflogen();
		vector<Flughafen> fliegen(vector<Flughafen> flughaefen);
		void flugtag_zuruecksetzen();
		void fliegen();
		void zeige_fluege();

	public:
		Flugtag();

		void set_flug_geringste_auslastung(Flug flieger);
		void set_flug_hoechste_auslastung(Flug flieger);
		void set_flughafen_geringster_durchsatz_angekommen(Flughafen flughafen);
		void set_flughafen_hoechster_durchsatz_angekommen(Flughafen flughafen);
		void set_flughafen_geringster_durchsatz_abgeflogen(Flughafen flughafen);
		void set_flughafen_hoechster_durchsatz_abgeflogen(Flughafen flughafen);
		void set_anz_passagiere_ges(int die_passagiere);

		Flug get_flug_geringste_auslastung();
		Flug get_flug_hoechste_auslastung();
		Flughafen get_flughafen_geringster_durchsatz_angekommen();
		Flughafen get_flughafen_hoechster_durchsatz_angekommen();
		Flughafen get_flughafen_geringster_durchsatz_abgeflogen();
		Flughafen get_flughafen_hoechster_durchsatz_abgeflogen();
		vector<Flughafen> get_flughaefen();
		double get_auslastung();

		Flugtag(int anz);
		void simuliere_fluege();




};

#endif /* FLUGTAG_H_ */
