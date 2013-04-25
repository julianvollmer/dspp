//
//  PathVector.h
//  shortPath
//
//  Created by Julian Vollmer on 21.04.13.
//  Copyright (c) 2013 Julian Vollmer. All rights reserved.
//

#ifndef __shortPath
#define __shortPath

#include <vector>
#include <iostream>
#include "PathElement.h"
#include "../helper/random.h"
#include "../helper/ausgabe.h"
using namespace std;


class PathVector {
    
public:
    vector<PathElement> vec;

    PathVector();
    void add_element(PathElement element);
    void print_vector();
    void generate_distance_for_element(PathElement *element);
    void fill_rest_of_vector();
    void test();
};


#endif /* defined(__shortPath) */
