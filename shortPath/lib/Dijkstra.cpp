#include "Dijkstra.h"

Dijkstra::Dijkstra(){};

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
        cout << "(" << source(*edge_iter, g) << " -> " << target(*edge_iter, g) << ")\n";
    }

    cout << "\n";
    //Want to add another edge between (A,E)?
    add_edge(A, E, g);

    //Print out the edge list again to see that it has been added
    for(edge_iterator edge_iter = ei.first; edge_iter != ei.second; ++edge_iter) {
        cout << "(" << source(*edge_iter, g) << " -> " << target(*edge_iter, g) << ")\n";
    }

    //Finally lets add a new vertex - remember the verticies are just of type int
    int F = add_vertex(g);
    cout << F << "\n";

    //Connect our new vertex with an edge to A...
    add_edge(A, F, g);

    //...and print out our edge set once more to see that it was added
    for(edge_iterator edge_iter = ei.first; edge_iter != ei.second; ++edge_iter) {
        cout << "(" << source(*edge_iter, g) << " -> " << target(*edge_iter, g) << ")\n";
    }
}
void Dijkstra::setSource(unsigned int root) {
    this->root = root;
}


void Dijkstra::setMatrix(unsigned int matrix[nodenum][nodenum]) {
    memcpy(this->matrix, matrix, nodenum * nodenum * sizeof(unsigned int));
}


void Dijkstra::calculate(bool step = false) {

    // Array für markierte Knoten
    bool marked[nodenum];

    // Initialisierung
    for(int x = 0; x < nodenum; ++x) {
        // Kein Knoten ist markiert
        marked[x] = false;

        // Kosten sind zunächst unendlich (INF = INT_MAX)
        this->distance[x] = INF;

        // Vorgänger sind nicht vorhanden
        this->predecessor[x] = 0;
    }
 
    // Startknoten besitzt Kosten 0
    this->distance[this->root] = 0;

    bool flag = true;

    while(flag) {
        // minimale Kosten initialisieren
        unsigned int minimum = INF;

        // zugehöriger (minimaler) Knoten
        int node = 0;

        // Minimale Distanz ermitteln
        for(int j = 0; j < nodenum; ++j) {
            // Knoten schon markiert -> überspringen (Zyklen vermeiden!)
            if(marked[j]) continue;

            // Distance kleiner als Minimum -> neues Minimum gefunden
            if(this->distance[j] < minimum) {
                minimum = this->distance[j];
                node = j;
            }
        }

        // Distanz aktualisieren, wenn Zielknoten über den gefundenen Minimumknoten billiger erreichbar
        for(int j = 0; j < nodenum; ++j) {
            if(!marked[j] && this->matrix[node][j] != 0 && this->distance[node] + this->matrix[node][j] < this->distance[j]) {
                this->distance[j] = this->distance[node] + this->matrix[node][j];
                this->predecessor[j] = node;
            }

            // jeden einzelnen Verbesserungsschritt ausgeben?
            if(step == true)
                (this->distance[j] == INF) ? printf("INF\t") : printf("%3d\t", this->distance[j]);
        }

        if(step == true)
            printf("\n\n");
        
        // gerade bestimmten Minimumknoten markieren
        marked[node] = true;

        // sind noch Knoten unmarkiert?
        flag = false;
        for(int j = 0; j < nodenum && !flag; ++j) {
            flag = !marked[j];
        }
    }
}


// Methode, die den günstigsten Weg vom angegebenen Startknoten zu den anderen Knoten aufzeigt
void Dijkstra::trace() {

    for(int x = 0; x < nodenum; ++x) {
        // Wenn kein Vorgänger vorhanden und Knoten != Startknoten existiert keine Verbindung
        if(this->predecessor[x] == 0 && x != this->root) {
            printf("Keine Verbindung zwischen %d und %d gefunden\n\n", this->root, x);
            continue;
        }

        printf("G\\x81nstigste Verbindung von %d nach %d\n", root, x);

        int j = x;

        // Vorgänger verfolgen bis zum Ziel ("Rückwärtssuche")
        while(this->predecessor[j] != 0) {
            printf("%d <- ", j);
            j = this->predecessor[j];
        }

        printf("%d \n \nKosten: %3d \n \n", j, this->distance[x]);
 }
}
