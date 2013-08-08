#ifndef _HELPERS_H
#define	_HELPERS_H
#include <iostream>
#include <stdlib.h>
#include <sstream>

#include "eingabe.h"

using namespace std;

int string_to_number(string str);
string concat_string_and_int(string str, int i);
int menu();
string konvertiere_int(int number);
bool parameter_ok(int argc, char *argv[]);
void print_header();
void print_footer();
void load_graph_from_file();
void help();

#endif /*_HELPERS_H*/

