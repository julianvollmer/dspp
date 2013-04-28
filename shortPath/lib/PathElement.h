//
//  PathElement.h
//  shortPath
//
//  Created by Julian Vollmer on 21.04.13.
//  Copyright (c) 2013 Julian Vollmer. All rights reserved.
//

#ifndef __shortPath
#define __shortPath

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
    void set_distance(int pos, int value);
    string get_name();
};


#endif /* defined(__shortPath) */
