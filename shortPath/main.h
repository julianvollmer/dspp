/**
 * 
 */
#ifndef MAIN_H_
#define MAIN_H_
#include <iostream>
#include "lib/PathElement.h"
#include "lib/PathVector.h"
#include "helper/random.h"
#include "helper/ausgabe.h"
#include "helper/eingabe.h"

void anleitung();
int menu();
void testing_purpose(int counter);
bool parameter_ok(int argc, char *argv[]);
void verarbeite_eingabe(int weiter, PathVector *p);
#endif /* MAIN_H_ */