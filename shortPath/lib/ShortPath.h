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

// Anzahl an Knoten muss "hart" festgelegt werden
#define nodenum 99999

class ShortPath {

public:
	ShortPath();

    /*
    * Function read() reads No of vertices, Adjacency Matrix and source
    * Matrix from the user. The number of vertices must be greather than
    * zero, all members of Adjacency Matrix must be postive as distances
    * are always positive. The source vertex must also be positive from 0
    * to noOfVertices - 1
    */
    void read();

    void show_dk();
 
    /*
    * Function initialize initializes all the data members at the begining of
    * the execution. The distance between source to source is zero and all other
    * distances between source and vertices are infinity. The mark is initialized
    * to false and predecessor is initialized to -1
    */
    void initialize();
 
    /*
    * Function get_closed_unmarked_node returns the node which is nearest from the
    * Predecessor marked node. If the node is already marked as visited, then it search
    * for another node.
    */
    int get_closest_unmarked_node();
    
    /*
    * Function calculate_distance calculates the minimum distances from the source node to
    * Other node.
    */
    void calculate_distance();
    void calculate_distance_multiproc();
    void add_row(Dijkstra element);
    int size();
    /*
    * Function output prints the results
    */
    void output();


    void init_random_distances();

    vector<Dijkstra> get_elements();



    void printPath(int);    
    // void setMatrix(unsigned int matrix[nodenum][nodenum]);
    // void get(unsigned int (*&retVal)[nodenum][nodenum]);
    void init_random();
    void init_random(int anz);
    void init_source();
    void add_random_row();
    void print();

private:
    vector<Dijkstra> elements;
    vector<int> distances;
    
    unsigned int predecessor[nodenum]; // Array für Vorgängerknoten
    
    
    int source;
    int num_of_vertices;    

    void print_horizontal_line();
    void reflect_to_other_side();
};

#endif /* __shortpath */
