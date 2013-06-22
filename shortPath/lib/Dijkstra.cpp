#include "Dijkstra.h"

#include <limits.h>

Dijkstra::Dijkstra(){
    init_distances();
};


/** 
 * Returns all distances to the other edges in a vector
 * @return
 */
vector<int> Dijkstra::get_distances_to_other(){
    return this->distances;
    
}

/**
 * All distance has to be INT_MAX at the begining
 */
void Dijkstra::init_distances(){
    for(int i = 0; i < distances.size(); i++){
        distances[i] = INT_MAX;
    }
}

/**
 * Returns the distance to a specific edge
 * @param  position position of the edge
 * @return          distance
 */
int Dijkstra::get_distance_from_specific(int position){
    if(position < distances.size())
        return distances[position];
    else
        return 0;
}

/**
 * Sets the distance to a specific edge
 * @param position target
 * @param value    distance
 */
void Dijkstra::set_distance_to_specific(int position, int value){
    if(position < distances.size())
        distances[position] = value;
}
/**
 * Returns the name of the edge
 * @return Returns the name of the edge
 */
string Dijkstra::get_name(){
    return this->name;
}

/**
 * Returns the distance to the target edge
 * @return Returns the distance to the target edge
 */
int Dijkstra::get_distance(){
    return this->distance;
}

/**
 * Returns the predecessor
 * @return Returns the predecessor
 */
int Dijkstra::get_predecessor(){
    return this->predecessor;
}

/**
 * Returns if a edge is visited or not
 * @return Returns if a edge is visited or not
 */
bool Dijkstra::get_mark(){
    return this->mark;
}

int Dijkstra::get_position(){
    return this->position;  
}

int Dijkstra::get_shortest_distance(){
    int min_distance = INT_MAX;
    for(int i = 0; i < distances.size();i++)
    {   
        if(min_distance > distances[i])
            min_distance =  distances[i];

    }
    return min_distance;
}


void Dijkstra::add_distance(int distance){
    if(this->distance == INT_MAX )
        this->distance = 0;
    this->distance += distance;
}

void Dijkstra::set_name(string name){
    this->name = name;
}

void Dijkstra::set_distance(int distance){
    this->distance = distance;
}

void Dijkstra::set_predecessor(int predecessor){
    this->predecessor = predecessor;
}

void Dijkstra::set_mark(bool mark){
    this->mark = mark;
}


void Dijkstra::set_distance_vector(vector<int> v){
    this->distances = v;
}


void Dijkstra::add_distances_to_other(int distance){
    this->distances.push_back(distance);
}



void Dijkstra::set_position(int position){
    this->position = position;
}

/**
 * Prints the distance to the root edge
 */
void Dijkstra::print_distances(){
    cout << this->name << '\t';
    for (vector<int>::iterator it = distances.begin() ; it != distances.end(); ++it){
            cout << *it << '\t';

    }
    cout << endl;
}
