//
//  PathElement.h
//  shortPath
//
//  Created by Julian Vollmer on 21.04.13.
//  Copyright (c) 2013 Julian Vollmer. All rights reserved.
//

#ifndef __load_file
#define __load_file

#include <iostream>
#include <vector>
#include <fstream> 
#include "helpers.h"
#include "../lib/ShortPath.h"
#include "../lib/Dijkstra.h"

using namespace std;
	void load_file();
	void create_nodes_from_file_char(char c);
	void add_row(vector<int> v);	
	bool validate_dataformat();
	ShortPath* getShortPathObject();
#endif /* defined(__load_file) */
