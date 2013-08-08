#ifndef _EINGABE_H
#define	_EINGABE_H
#include <iostream>
#include <limits>
#include <cfloat>
#include <limits.h>
#include <string.h>
using namespace std;

void eingabe();
long erfasse_long(long min, long max);
long erfasse_long(long min, long max, string text);
double erfasse_double(double min, double max);

double erfasse_double(double min, double max);
double erfasse_double();
double erfasse_double(string text);
double erfasse_double(string text, double min, double max);

int erfasse_int(int min, int max, string text);
int erfasse_int(string text);
int erfasse_int();
int erfasse_int(int min, int max);
int is_numeric(char* str);
int pruefe_bereich_int(int wert, int min, int max);
#endif
