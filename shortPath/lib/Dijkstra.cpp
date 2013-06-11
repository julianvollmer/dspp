#include "Dijkstra.h"


Dijkstra::Dijkstra(){
    init_distances();
};

vector<int> Dijkstra::get_distances_to_other(){
    return this->distances;
    
}

void Dijkstra::init_distances(){
    for(int i = 0; i < distances.size(); i++){
        distances[i] = INT_MAX;
    }
}

int Dijkstra::get_distance_from_specific(int position){
    if(position < distances.size())
        return distances[position];
    else
        return 0;
}

string Dijkstra::get_name(){
    return this->name;
}

int Dijkstra::get_distance(){
    return this->distance;
}

int Dijkstra::get_predecessor(){
    return this->predecessor;
}

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



void Dijkstra::add_distances_to_other(int distance){
    this->distances.push_back(distance);
}


void Dijkstra::set_position(int position){
    this->position = position;
}

void Dijkstra::print_distances(){
    cout << this->name << '\t';
    for (vector<int>::iterator it = distances.begin() ; it != distances.end(); ++it){
            cout << *it << '\t';

    }
    cout << endl;
}
