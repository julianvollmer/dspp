//
//  PathVector.h
//  shortPath
//
//  Created by Julian Vollmer on 21.04.13.
//  Copyright (c) 2013 Julian Vollmer. All rights reserved.
//

#ifndef __shortPath__PathVector__
#define __shortPath__PathVector__

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
    void generateDistancesForElement(PathElement *element);
    
    // vector<vector <int> > vec;
};


#endif /* defined(__shortPath__PathVector__) */
