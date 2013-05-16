#include "Dijkstra.h"

Dijkstra::Dijkstra(){};

void Dijkstra::test_funktion(){	
	cout << "alksdma";
}

void Dijkstra::test_boost(){
 //create an -undirected- graph type, using vectors as the underlying containers
    //and an adjacency_list as the basic representation
    typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS> UndirectedGraph;

    //Our set of edges, which basically are just converted into ints (0-4)
    enum {A, B, C, D, E, N};
    const char *name = "ABCDE";

    //An edge is just a connection between two vertitices. Our verticies above
    //are an enum, and are just used as integers, so our edges just become
    //a pair<int, int>
    typedef pair<int, int> Edge;

    //Example uses an array, but we can easily use another container type
    //to hold our edges. 
    vector<Edge> edgeVec;
    edgeVec.push_back(Edge(A,B));
    edgeVec.push_back(Edge(A,D));
    edgeVec.push_back(Edge(C,A));
    edgeVec.push_back(Edge(D,C));
    edgeVec.push_back(Edge(C,E));
    edgeVec.push_back(Edge(B,D));
    edgeVec.push_back(Edge(D,E));

    //Now we can initialize our graph using iterators from our above vector
    UndirectedGraph g(edgeVec.begin(), edgeVec.end(), N);

    cout << num_edges(g) << "\n";

    //Ok, we want to see that all our edges are now contained in the graph
    typedef boost::graph_traits<UndirectedGraph>::edge_iterator edge_iterator;

    //Tried to make this section more clear, instead of using tie, keeping all
    //the original types so it's more clear what is going on
    pair<edge_iterator, edge_iterator> ei = edges(g);
    
    for(edge_iterator edge_iter = ei.first; edge_iter != ei.second; ++edge_iter) {
        cout << "(" << source(*edge_iter, g) << ", asda" << target(*edge_iter, g) << ")\n";
    }

    cout << "\n";
    //Want to add another edge between (A,E)?
    add_edge(A, E, g);

    //Print out the edge list again to see that it has been added
    for(edge_iterator edge_iter = ei.first; edge_iter != ei.second; ++edge_iter) {
        cout << "( A" << source(*edge_iter, g) << ", " << target(*edge_iter, g) << ")\n";
    }

    //Finally lets add a new vertex - remember the verticies are just of type int
    int F = add_vertex(g);
    cout << F << "\n";

    //Connect our new vertex with an edge to A...
    add_edge(A, F, g);

    //...and print out our edge set once more to see that it was added
    for(edge_iterator edge_iter = ei.first; edge_iter != ei.second; ++edge_iter) {
        cout << "(" << source(*edge_iter, g) << ", " << target(*edge_iter, g) << ")\n";
    }
    
}



// http://www.cprogramming.com/tutorial/computersciencetheory/dijkstra.html
// Given a graph, G, with edges E of the form (v1, v2) and vertices V, and a
// source vertex, s

// dist : array of distances from the source to each vertex
// prev : array of pointers to preceding vertices
// i    : loop index
// F    : list of finished vertices
// U    : list or heap unfinished vertices

// /* Initialization: set every distance to INFINITY until we discover a path */
// for i = 0 to |V| - 1
//     dist[i] = INFINITY
//     prev[i] = NULL
// end

// /* The distance from the source to the source is defined to be zero */
// dist[s] = 0

//  This loop corresponds to sending out the explorers walking the paths, where
//  * the step of picking "the vertex, v, with the shortest path to s" corresponds
//  * to an explorer arriving at an unexplored vertex 

// while(F is missing a vertex)
//    pick the vertex, v, in U with the shortest path to s
//    add v to F
//    for each edge of v, (v1, v2)
//         /* The next step is sometimes given the confusing name "relaxation"
//         if(dist[v1] + length(v1, v2) < dist[v2])
//             dist[v2] = dist[v1] + length(v1, v2)
//             prev[v2] = v1
//             possibly update U, depending on implementation
//         end if
//     end for
// end while