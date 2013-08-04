#ifndef _HELPERS_H
#define	_HELPERS_H
#include <iostream>
#include <stdlib.h>
#include <sstream>


#include "eingabe.h"

using namespace std;

int string_to_number(string str);
string concat_string_and_int(string str, int i);

void help();
int menu();
bool parameter_ok(int argc, char *argv[]);

#endif /*_HELPERS_H*/
string konvertiere_int(int number);
