//
//  <.cpp
//  shortPath
//
//  Created by Julian Vollmer on 21.04.13.
//  Copyright (c) 2013 Julian Vollmer. All rights reserved.
//

#include "PathVector.h"

/**
 * ctor
 */
PathVector::PathVector(){};



void PathVector::generate_distance_for_element(PathElement *element){
	int length = vec.size();
	vector<int> distanceVector(length);
	int tmp = 0;
	
	for(int i = 0; i < length; i++){
		tmp = liefere_ganze_zufallszahl(1,99);
		distanceVector[i] = tmp;
	}
	
	distanceVector.push_back(tmp);
	element->setDistances(distanceVector);
}

void PathVector::fill_rest_of_vector(){
	for(int j = 0; j < vec.size();j++){
		for(int i = j+1; i < vec.size();i++){
			vec[j].push_back(vec[i][j]);	
		}
	}
}

/**
 * [PathVector::addElement description]
 * add one element to the multidimensionell vector.
 * @param distance distance to all other points.
 */
void PathVector::addElement(PathElement element){
	generate_distance_for_element(&element);
	vec.push_back(element.getDistances());
}

void PathVector::set_diagonale_zero(){
	for(int i = 0; i < vec.size(); i++){
		vec[i][i] = 0;
	}	
}

void PathVector::printVector(){
	vector<vector<int> >::iterator vec_it;
	vector<int>::iterator inner_it;

	for(vec_it = vec.begin(); vec_it != vec.end(); ++vec_it){
		for(inner_it = vec_it->begin(); inner_it != vec_it->end(); ++inner_it){
			// cout<<*inner_it<<' ';
			schreibe_text(convertInt(*inner_it), 12);
		}
		cout << endl;
	}
	cout<<endl;
}





