/**
 * 
 */

/**
\mainpage The mainpage documentation

This is a simple example of a mainpage you can create yourself.
Place this inside of a file called `mainpage.dox` and use doxygen.
If you specified `INPUT` or `FILE_PATTERNS` in your Doxyfile please
add `.dox` to your file patterns or `mainpage.dox` to your INPUT files.
*/
#ifndef MAIN_H_
#define MAIN_H_
#include "iostream"
#include "lib/Dijkstra.h"
#include "lib/ShortPath.h"
#include "helper/random.h"
#include "helper/ausgabe.h"
#include "helper/eingabe.h"
#include "helper/load_file.h"
#include "helper/write_file.h"
#include "time.h"





void verarbeite_eingabe(int weiter, ShortPath *sp);
void boost_it();
void set_starting_point(Dijkstra *dk);
void test_new_dijkstra(Dijkstra *dk);
void do_shortpath_calculation(ShortPath *sp);
void do_shortpath_calculation_mulitproc(ShortPath *sp);
void set_number_of_graphs(ShortPath *sp);
void set_number_of_cores(ShortPath *sp);
void load_graph_from_file();
void show_test();
void show_test(ShortPath *sp);
void full_path_search(ShortPath *sp);
void full_path_search_multi(ShortPath *sp);

clock_t start, stop;
double t;
int number_of_graphs;
int number_of_cores;
ShortPath *sp = new ShortPath();
#endif /* MAIN_H_ */
