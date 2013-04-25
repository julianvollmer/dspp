//
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
	for(int i = 0; i < length; i++){
		element->push_distance(liefere_ganze_zufallszahl(2,99));
	}
	element->push_distance(0);

}

/**
 * [PathVector::addElement description]
 * add one element to the multidimensionell vector.
 * @param distance distance to all other points.
 */
void PathVector::add_element(PathElement element){

	generate_distance_for_element(&element);

	vec.push_back(element);
}

void PathVector::test(){
	vec[2].push_distance(123);
}




void PathVector::print_vector(){
	vector<PathElement >::iterator it;
	vector<int >::iterator dis_it;
	int field_size = 8;
	for (it = vec.begin() ; it != vec.end(); ++it){
		schreibe_text((*it).get_name(), field_size);

		for(dis_it =(*it).get_distances().begin(); dis_it != (*it).get_distances().end(); ++dis_it){
			schreibe_text(konvertiere_int(*dis_it), field_size);
		}
		cout<<endl;
	}
}





