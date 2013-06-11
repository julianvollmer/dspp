/**
 * 
 */
#ifndef MAIN_H_
#define MAIN_H_
#include <iostream>
#include "lib/Dijkstra.h"
 #include "lib/ShortPath.h"
#include "helper/random.h"
#include "helper/ausgabe.h"
#include "helper/eingabe.h"
#include "helper/load_file.h"



void anleitung();
int menu();
void testing_purpose(int counter);
bool parameter_ok(int argc, char *argv[]);
void verarbeite_eingabe(int weiter, Dijkstra *dk);
void boost_it();
void set_starting_point(Dijkstra *dk);
void test_new_dijkstra(Dijkstra *dk);

#endif /* MAIN_H_ */