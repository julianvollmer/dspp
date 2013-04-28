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

PathVector::PathVector(int anzahl){
	
};

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
	// for(int i = 0; i < vec.size(); i++){
	 	if(vec.size() > 1 )
	 	vec[0].push_distance(element.get_distance(0));
	// }
}

void PathVector::add_random_elements(int anzahl){
	int anz = vec.size();
	for(int i = 0; i < anzahl; i++){
		anz++;
		PathElement *p = new PathElement;
		p->set_name("Julian" + konvertiere_int(anz));
		
		add_element(*p);
	}
}

void PathVector::fill(){
	int vec_size = vec.size();
	for(int i = 0; i < vec_size; i++){
		for(int j = i+1; j < vec_size; j++)
			vec[i].push_distance(vec[j].get_distance(i));	
	}
	
}



void PathVector::mark_node(){
	vec[1].set_distance(2,1337);
}

void PathVector::print_vector(){

	vector<PathElement >::iterator it;
	vector<int >::iterator dis_it;
	int field_size = 11;

	 schreibe_text("v Knoten >", field_size); // hier mit adjustfield left arbeiten, weiß nicht genau wie das geht, die ausgabe c++ kann es aber nochmal genau schauen wie man das verwendet...
	 for (it = vec.begin() ; it != vec.end(); ++it){
	 	schreibe_text((*it).get_name(), field_size);

	 }
	 cout << endl;
	for(int i = 0; i < ((vec.size()+1)*field_size);i++)
		cout << "-";
	cout << endl;
	for (it = vec.begin() ; it != vec.end(); ++it){
		schreibe_text((*it).get_name()+"|", field_size);
		

		 for(dis_it =(*it).get_distances().begin(); dis_it != (*it).get_distances().end(); ++dis_it){
		 	schreibe_text(konvertiere_int(*dis_it), field_size);
		 }
		cout<<endl;
	}
}

void PathVector::print_shortest_way(){
	vector<PathElement >::iterator it;
	for (it = vec.begin() ; it != vec.end(); ++it){
	 	schreibe_text((*it).get_name(), 11);
	 }
	 cout << endl;

	 Dijkstra *d = new Dijkstra;
	 d->test_funktion();

}

