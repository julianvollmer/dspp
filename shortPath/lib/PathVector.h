//
//  PathVector.h
//  shortPath
//
//  Created by Julian Vollmer on 21.04.13.
//  Copyright (c) 2013 Julian Vollmer. All rights reserved.
//

#ifndef __pathVector
#define __pathVector

#include <vector>
#include <iostream>
#include "PathElement.h"
#include "../helper/random.h"
#include "../helper/ausgabe.h"
#include "Dijkstra.h"

using namespace std;


class PathVector {
    
public:
    vector<PathElement> vec;

    PathVector();
    PathVector(int anzahl);
    void add_element(PathElement element);
    void print_vector();
    void generate_distance_for_element(PathElement *element);
    void fill_rest_of_vector();
    void fill();
    void mark_node();
    void add_random_elements(int anzahl);
    void print_shortest_way();
};


#endif /* defined(__pathVector) */
