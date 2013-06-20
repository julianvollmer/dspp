#ifndef __writefile
#define __writefile

#include <iostream>
#include <fstream>
#include "../lib/ShortPath.h"

using namespace std;


void write_graph_to_file(ShortPath *sp);
bool is_file_aviable(string filename);

#endif /* __writefile */
