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
#include <time.h>



void anleitung();
int menu();
void testing_purpose(int counter);
bool parameter_ok(int argc, char *argv[]);
void verarbeite_eingabe(int weiter, ShortPath *sp);
void boost_it();
void set_starting_point(Dijkstra *dk);
void test_new_dijkstra(Dijkstra *dk);
void do_shortpath_calculation(ShortPath *sp);
void do_shortpath_calculation_mulitproc(ShortPath *sp);
void set_number_of_graphs(ShortPath *sp);
void set_number_of_cores(ShortPath *sp);

clock_t start, stop;
double t;
int number_of_graphs;
int number_of_cores;

#endif /* MAIN_H_ */
