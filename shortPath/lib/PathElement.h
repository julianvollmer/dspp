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
    void set_name(string name);
    void push_distance(int dist);
    vector<int> get_distances();
    int get_distance(int pos);

    string get_name();
};


#endif /* defined(__shortPath__PathElement__) */
