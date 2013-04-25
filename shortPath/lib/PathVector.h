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
    vector< vector<int> > vec;

    PathVector();
    void addElement(PathElement element);
    void printVector();
    void generate_distance_for_element(PathElement *element);
    void fill_rest_of_vector();
    void set_diagonale_zero();
};


#endif /* defined(__shortPath) */
