//
//  PathElement.cpp
//  shortPath
//
//  Created by Julian Vollmer on 21.04.13.
//  Copyright (c) 2013 Julian Vollmer. All rights reserved.
//

#include "PathElement.h"

/**
 * ctor
 */
PathElement::PathElement(){};

void PathElement::setName(string name){
	this->name = name;
}

string PathElement::getName(){
	return this->name;
}

void PathElement::setDistances(vector<int> distance){
	this->distance = distance;
}

vector < int > PathElement::getDistances(){
	return this->distance;
}

