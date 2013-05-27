#ifndef __dijkstra
#define __dijkstra

#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

#include "../helper/eingabe.h"
#include "../helper/helpers.h"

#include "boost/graph/graph_traits.hpp"
#include "boost/graph/adjacency_list.hpp"
using namespace std;

// Unendlich "definieren"
#define INF INT_MAX

// Anzahl an Knoten muss "hart" festgelegt werden
#define nodenum 9



class Dijkstra {
    
public:
	Dijkstra(); 


        /*
    * Function read() reads No of vertices, Adjacency Matrix and source
    * Matrix from the user. The number of vertices must be greather than
    * zero, all members of Adjacency Matrix must be postive as distances
    * are always positive. The source vertex must also be positive from 0
    * to noOfVertices - 1
 
    */
        void read();
 
    /*
    * Function initialize initializes all the data members at the begining of
    * the execution. The distance between source to source is zero and all other
    * distances between source and vertices are infinity. The mark is initialized
    * to false and predecessor is initialized to -1
    */
 
        void initialize();
 
    /*
    * Function getClosestUnmarkedNode returns the node which is nearest from the
    * Predecessor marked node. If the node is already marked as visited, then it search
    * for another node.
    */
 
        int getClosestUnmarkedNode();
    /*
    * Function calculateDistance calculates the minimum distances from the source node to
    * Other node.
    */
 
        void calculateDistance();
    /*
    * Function output prints the results
    */
 
        void output();
        void printPath(int);
    
    void setMatrix(unsigned int matrix[nodenum][nodenum]);
    void setSource(unsigned int root);
    void calculate(bool step);
    void trace();

    void get(unsigned int (*&retVal)[nodenum][nodenum])
     {
        retVal = &intern;
     }
     
private:
    unsigned int intern[nodenum][nodenum];
    
    unsigned int root;
    unsigned int distance[nodenum];         // Array für Entfernungen/Kosten
    unsigned int predecessor[nodenum]; 
    int adjMatrix[nodenum][nodenum];
    // int predecessor[nodenum],distance[nodenum];
    bool mark[nodenum]; //keep track of visited node
    int sources;
    int numOfVertices;     // Array für Vorgängerknoten
};

#endif /* __dijkstra */