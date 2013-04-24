//
//  PathElement.h
//  shortPath
//
//  Created by Julian Vollmer on 21.04.13.
//  Copyright (c) 2013 Julian Vollmer. All rights reserved.
//

#ifndef __shortPath__PathElement__
#define __shortPath__PathElement__

#include <iostream>
#include <vector>
using namespace std;


class PathElement {
    int zahl;
    string name;
    vector<int> distance;
    
public:
    PathElement();
    void writeHelloWorld();
    void setName(string name);
    void setDistances(vector<int> distance);
    vector<int> getDistances();
    string getName();
};


#endif /* defined(__shortPath__PathElement__) */
