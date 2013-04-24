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



void PathVector::generateDistancesForElement(PathElement *element){
	int vecLength = vec.size();
	vector<int> distanceVector(vecLength);
	for (int i = 0; i < vecLength; ++i){
		int tmp = liefere_ganze_zufallszahl(1,99);
		distanceVector[i] = tmp;

	}


	int length = distanceVector.size();
	
	if(length != 0)
		distanceVector[length-1] = 0;
	
	element->setDistances(distanceVector);
}

void PathVector::fillRestOfVector(){
	
	vec[1].push_back(vec[2][0]);
	vec[1].push_back(vec[3][0]);
	vec[1].push_back(vec[4][0]);


}

/**
 * [PathVector::addElement description]
 * add one element to the multidimensionell vector.
 * @param distance distance to all other points.
 */
void PathVector::addElement(PathElement element){

	generateDistancesForElement(&element);
	

	vector<int>::iterator it;
	std::vector<int> distance_tmp;
	distance_tmp = element.getDistances();

	vector< vector<int> > tmp_vec(1, vector<int>(distance_tmp.size()));

	tmp_vec[0] = distance_tmp; 


	vec.insert(vec.end(),tmp_vec.begin(),tmp_vec.end());
	
}


void PathVector::printVector(){

	vector<vector<int> >::iterator vec_it;
	vector<int>::iterator inner_it;


	for(vec_it = vec.begin(); vec_it != vec.end(); ++vec_it){
		cout << endl;
		for(inner_it = vec_it->begin(); inner_it != vec_it->end(); ++inner_it){
			// cout<<*inner_it<<' ';
			schreibe_text(convertInt(*inner_it), 12);
		}
	}
	cout<<endl;
}





