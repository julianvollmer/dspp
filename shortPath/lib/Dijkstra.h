#ifndef __dijkstra
#define __dijkstra

#include <vector>
#include <iostream>
using namespace std;

class Dijkstra {

public:
	Dijkstra();

    string      get_name();
    int         get_distance();
    vector<int> get_distances_to_other();
    int         get_predecessor();
    bool        get_mark();
    int         get_position();
    void        set_name(string name);
    void        set_distance(int distnace);
    void        set_predecessor(int predecessor);
    void        set_mark(bool mark);    
    void        add_distances_to_other(int distance);   
    void        set_position(int position);
    void        print_distances();
    int         get_distance_from_specific(int position);
    void        set_distance_to_specific(int position, int value);
    void        add_distance(int distance);
    void        init_distances();
    int         get_shortest_distance();
private:
    
    int predecessor;// Array für Vorgängerknoten
    bool mark;//keep track of visited node
    string name;
    vector<int> distances;
    int position;
    int distance;

    void        set_distance_to_myself_zero();

    
    
};

#endif /* __dijkstra */
