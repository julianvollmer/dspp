/**
\mainpage Hallo Welt!

Das Programm wurde von Julian Vollmer (s0525904) und Philip Stewart (s0526571) im Rahmen des Faches M31.2 Distributed Systems and Parallel Processing im Master Angewandte Informatik der Hochschule fuer Technik und Wirtschaft Berlin erstellt. Es Demonstriert die Suche des kürzesten Weges mit Hilfe des Dijkstra Algorithmus. Zum einen Wurde die Berechnung mit Hilfe eines Threads durchgeführt, weiterhin es möglich die Berechnung auf mehrere Threads zu verteilen. Das Hauptmerkmal wurde auf den Speedup gelegt welche im direkten Vergleich bei Wahl des Menüpunktes `Zeige Vergleichstest` ausgeführt wird.
*/

#ifndef MAIN_H_
#define MAIN_H_

#include "iostream"
#include "time.h"

#include "lib/Dijkstra.h"
#include "lib/ShortPath.h"
#include "helper/random.h"
#include "helper/ausgabe.h"
#include "helper/eingabe.h"
#include "helper/load_file.h"
#include "helper/write_file.h"

void verarbeite_eingabe(int weiter, ShortPath *sp);
void set_number_of_graphs(ShortPath *sp);
void set_num_of_threads(ShortPath *sp);
void full_path_search(ShortPath *sp);
void full_path_search_multi(ShortPath *sp);
void do_shortpath_calculation(ShortPath *sp);
void do_shortpath_calculation_mulitproc(ShortPath *sp);
void do_one_run(ShortPath *sp);
void show_performance_test(ShortPath *sp);
void print_run(ShortPath *sp);

double start, stop;
double t;
int number_of_graphs;
int number_of_threads;
ShortPath *sp = new ShortPath();

#endif /* MAIN_H_ */
