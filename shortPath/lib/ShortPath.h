#ifndef __shortpath
#define __shortpath

#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <omp.h>

#include "../helper/eingabe.h"
#include "../helper/helpers.h"
#include "../helper/random.h"

#include "Dijkstra.h"

#include "boost/graph/graph_traits.hpp"
#include "boost/graph/adjacency_list.hpp"
using namespace std;

// Unendlich "definieren"
#define INF INT_MAX

class ShortPath {

public:
	ShortPath();

    int get_num_of_vertices();
    void set_source(int src);
    void initialize();
    int get_closest_unmarked_node();
    void calculate_distance();
    void calculate_distance_multiproc();
    void add_row(Dijkstra element);
    void output();
    void init_random_distances();
    vector<Dijkstra> get_elements();
    void printPath(int);    
    void init_random();
    void init_random(int anz);
    void init_source();
    void add_random_row();
    void print();
    void clear();
    void set_number_of_threads(int number);
private:
    vector<Dijkstra> elements;
    vector<int> distances;
    int source;
    int num_of_vertices;    
    void print_horizontal_line();
    void reflect_to_other_side();

};

#endif /* __shortpath */
