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


void PathVector::initVector(){
	
 	vector< vector<int> > tmp_vec(2, vector<int>(2));
    tmp_vec[0][0] = 10;
    tmp_vec[0][1] = 10;
    tmp_vec[1][0] = 10;
    tmp_vec[1][1] = 10;
    
    this->vec = tmp_vec;
	
}


void PathVector::generateDistancesForElement(PathElement element){
	int vecLength = vec.size();
	
	vector<int> distanceVector(vecLength);

	for (int i = 0; i < vecLength; ++i){
		distanceVector.push_back(liefere_ganze_zufallszahl(1,100));
	}
	

	element.setDistance(distanceVector);

	vector<int>::iterator itit;
	std::vector<int> distance_tmp;
	distance_tmp = element.getDistance();
	for(itit = distance_tmp.begin(); itit != distance_tmp.end(); ++itit){
		cout << *itit << " llele" << endl;
	}

}

/**
 * [PathVector::addElement description]
 * add one element to the multidimensionell vector.
 * @param distance distance to all other points.
 */
void PathVector::addElement(PathElement element){

	generateDistancesForElement(element);
	vector< vector<int> > tmp_vec(1, vector<int>(1));

	tmp_vec[0][0] = 123; //richtige Distanz angeben !!! XXX

	vec.insert(vec.end(),tmp_vec.begin(),tmp_vec.end());
	cout << ".size:" << vec.size() <<endl;
}


void PathVector::printVector(){

	vector<vector<int> >::iterator vec_it;
	vector<int>::iterator inner_it;


	for(vec_it = vec.begin(); vec_it != vec.end(); ++vec_it){
		cout << endl;
		for(inner_it = vec_it->begin(); inner_it != vec_it->end(); ++inner_it){
			cout<<*inner_it<<' ';
		}
	}
	cout<<endl;
}



