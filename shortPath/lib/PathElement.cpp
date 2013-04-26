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

void PathElement::set_name(string name){
	this->name = name;
}

string PathElement::get_name(){
	return this->name;
}

void PathElement::set_distance(int pos, int value){
	if(distance.size() > pos){
		
	}
		
}

void PathElement::push_distance(int dist){
	this->distance.push_back(dist);
}

vector < int > PathElement::get_distances(){
	return this->distance;
}

int PathElement::get_distance(int pos){
	return distance[pos];
}

