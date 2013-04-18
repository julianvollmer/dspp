#ifndef _MEIN_ZUFALL_H
#define _MEIN_ZUFALL_H
#include <cstdio>
#include <cstdlib>
#include <ctime>
void initialisiere_zufallsgenerator(void);
int zufallszahl_int(int max);
int liefere_ganze_zufallszahl(int min, int max);
double zufallszahl_dbl();
double zufallszahl_dbl_max(double max);
double zufallszahl_dbl_min_max(double min, double max);
#endif
