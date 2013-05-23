#ifndef __dijkstra
#define __dijkstra

#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

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
    
    void setMatrix(unsigned int matrix[nodenum][nodenum]);
    void setSource(unsigned int root);
    void calculate(bool step);
    void trace();

    void get(int (*&retVal)[10][20])
     {
        retVal = &intern;
     }

private:
    int intern[10][20];
    unsigned int matrix[nodenum][nodenum];
    unsigned int root;
    unsigned int distance[nodenum];         // Array für Entfernungen/Kosten
    unsigned int predecessor[nodenum];      // Array für Vorgängerknoten
};

#endif /* __dijkstra */