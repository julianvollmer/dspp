#ifndef _TABELLE_H
#define	_TABELLE_H
#include <iostream>
#include "eingabe.h"
#include "ausgabe.h"
#include "meine_math.h"
using namespace std;

void menu_ausgabe();
void zeige_tabelle(int auswahl, double start, double ende, streamsize praezision);
void gebe_funktion_aus(funcp func, double wert);
int erfasse_daten();
void zeige_zahl(funcp func, double wert, streamsize praezision);

#endif
