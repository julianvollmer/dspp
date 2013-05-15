#ifndef __dijkstra
#define __dijkstra

#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

#include "boost/graph/graph_traits.hpp"
#include "boost/graph/adjacency_list.hpp"
using namespace std;

class Dijkstra {
    
public:
    Dijkstra(); 
    void test_funktion();
    void test_boost();
};

#endif /* __dijkstra */