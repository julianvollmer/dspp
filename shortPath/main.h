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
#include "helper/load_file.h"
#include <utility>
#include <algorithm>
#include <vector>

#include "boost/graph/graph_traits.hpp"
#include "boost/graph/adjacency_list.hpp"

using namespace boost;

void anleitung();
int menu();
void testing_purpose(int counter);
bool parameter_ok(int argc, char *argv[]);
void verarbeite_eingabe(int weiter, PathVector *p);
void test_boost();
#endif /* MAIN_H_ */