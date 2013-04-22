#ifndef _RANDOM_H
#define _RANDOM_H
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
void initialisiere_zufallsgenerator(void);
int zufallszahl_int(int max);
int liefere_ganze_zufallszahl(int min, int max);
double zufallszahl_dbl();
double zufallszahl_dbl_max(double max);
double zufallszahl_dbl_min_max(double min, double max);
char liefere_zufallszahl_als_char();
string liefere_zufallszahl_als_string( int laenge);
#endif
