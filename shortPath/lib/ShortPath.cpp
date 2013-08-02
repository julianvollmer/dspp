#include "ShortPath.h"
/**
 * Constructor
 */
ShortPath::ShortPath(){
    omp_set_num_threads(4);
};

/**
 * @return Retuns all elements
 */
vector<Dijkstra> ShortPath::get_elements(){
    return this->elements;
}

/**
 * Delete a elements
 */
void ShortPath::clear(){
    this->elements.clear();
}

int ShortPath::get_num_of_vertices(){
    return num_of_vertices;
}

int ShortPath::set_source(int src){
    source = src;
}

int ShortPath::set_number_of_threads(int number){
    omp_set_num_threads(number);
}

/**
 * Adds a row to the matrix
 * @param element [description]
 */
void ShortPath::add_row(Dijkstra element){
    this->elements.push_back(element);
}
/**
 * initialize the graph random
 */
void ShortPath::init_random_distances(){
    int size = elements.size();    
    for (vector<Dijkstra>::iterator it = elements.begin() ; it != elements.end(); ++it){
        int pos = it->get_position();
        for(int i = 0; i < size && i < pos; i++){
            if((liefere_ganze_zufallszahl(0,1000)%1000)==0){
                it->add_distances_to_other(0);    
            }

            else {
                    it->add_distances_to_other(liefere_ganze_zufallszahl(1,250));    
                }
        }
        it->add_distances_to_other(0);
    }
    reflect_to_other_side();

} 


/**
 * Normalize the adjacency matrix so that the way from a 2 d same as d 2 a
 */
void ShortPath::reflect_to_other_side(){
    int tmp = 0;
    for (int j = 0; j < elements.size(); j++){
        for(int i = elements[j].get_position()+1; i < elements.size(); i++){
            tmp = elements[i].get_distance_from_specific(j);
            elements[j].add_distances_to_other(tmp);    
        }
    }
}

/**
 * prints the adjacency matrix.
 */
void ShortPath::print(){
    cout << '\t';     
    for (vector<Dijkstra>::iterator it = elements.begin() ; it != elements.end(); ++it){
         cout << it->get_name() << '\t';

    }

    cout << endl;
    print_horizontal_line();
    cout << endl;
    
    for (vector<Dijkstra>::iterator it = elements.begin() ; it != elements.end(); ++it){
            it->print_distances();

    }

    cout << endl;
    erfasse_enter();
}

/**
 * Prints a horizontal line between name an value
 */
void ShortPath::print_horizontal_line(){
    for (int i = 0; i < 8*elements.size()+1;i++){
        cout << '*';
    }
    cout << "***";
}

/**
 * Initialize the random initialisation
 * @param anz [description]
 */
void ShortPath::init_random(int anz){
    num_of_vertices = anz;
    elements.clear();
    for (int i = 0; i < num_of_vertices; i++){
        Dijkstra d;
        d.set_name(concat_string_and_int("J&P",i));
        d.set_mark(false);
        d.set_predecessor(-1);
        d.set_position(i);
        elements.push_back(d);
    }
    init_random_distances();
}

/**
 * initialize a Graph with a specific size
 */
void ShortPath::init_random(){
    num_of_vertices = erfasse_int(0,INFINITY,"Geben Sie die Anzahl der Knoten des Graphen ein:");    
    init_random(num_of_vertices);
}

/**
 * [ShortPath::init_source description]
 */
void ShortPath::init_source(){
     source = erfasse_int(0,num_of_vertices-1,"Enter the source vertex\n");
}

/**
 * Function initialize initializes all the data members at the begining of
 * the execution. The distance between source to source is zero and all other
 * distances between source and vertices are infinity. The mark is initialized
 * to false and predecessor is initialized to -1
 */

void ShortPath::initialize(){
    distances.clear();
    num_of_vertices = elements.size();
    for(int i=0;i<num_of_vertices;i++) {
        elements[i].set_mark(false);
        elements[i].set_predecessor(-1);
        distances.push_back(INFINITY);
    }
    distances[source]= 0;
}

/**
 * Function get_closed_unmarked_node returns the node which is nearest from the
 * Predecessor marked node. If the node is already marked as visited, then it search
 * for another node.
 * @return closest_unmarked_node closest unmarked node
 */
int ShortPath::get_closest_unmarked_node(){
    int minDistance = INFINITY;
    int closest_unmarked_node;
    for(int i=0;i<num_of_vertices;i++) {
        if((!elements[i].get_mark()) && ( minDistance >= distances[i])) {
            minDistance = distances[i];
            closest_unmarked_node = i;
        }
    }
    return closest_unmarked_node;
}
 
/**
 * Function calculate_distance calculates the minimum distances from the source node to
 * other node.
 */
void ShortPath::calculate_distance_multiproc(){
    
    
    initialize();
    int minDistance = INFINITY;
    int closest_unmarked_node;
    int count = 0;

    #pragma omp parallel   
    while(count < num_of_vertices) {
        closest_unmarked_node = get_closest_unmarked_node();
        elements[closest_unmarked_node].set_mark(true);
        for(int i = 0; i < num_of_vertices; i++) {
            if((!elements[i].get_mark()) && (elements[closest_unmarked_node].get_distance_from_specific(i) > 0) ) {
                if(distances[i] > distances[closest_unmarked_node] + elements[closest_unmarked_node].get_distance_from_specific(i)) {
                    distances[i] = distances[closest_unmarked_node] + elements[closest_unmarked_node].get_distance_from_specific(i);
                    elements[i].set_predecessor(closest_unmarked_node);
                }
            }
        }
        count++;
    }
}
/**
 * Function calculate_distance calculates the minimum distances from the source node to
 * other node.
 */
void ShortPath::calculate_distance(){
    
    initialize();
    int minDistance = INFINITY;
    int closest_unmarked_node;
    int count = 0;
    while(count < num_of_vertices) {
        closest_unmarked_node = get_closest_unmarked_node();
        elements[closest_unmarked_node].set_mark(true);
        for(int i = 0; i < num_of_vertices; i++) {
            if((!elements[i].get_mark()) && (elements[closest_unmarked_node].get_distance_from_specific(i) > 0) ) {
                if(distances[i] > distances[closest_unmarked_node] + elements[closest_unmarked_node].get_distance_from_specific(i)) {
                    distances[i] = distances[closest_unmarked_node] + elements[closest_unmarked_node].get_distance_from_specific(i);
                    elements[i].set_predecessor(closest_unmarked_node);
                }
                
            }
        }
        count++;
    }
}


 /**
  * Prints the path to the node
  * @param node Node or target
  */
void ShortPath::printPath(int node){

    if(node == source)
        cout << node << "..";
    else if(elements[node].get_predecessor() == -1)
        cout << "No path from "<<source<< " to "<< node <<endl;
    else {
        printPath(elements[node].get_predecessor());
        cout << node <<"..";
    }
}

 /**
  * print the output on the console
  */
void ShortPath::output(){
    for(int i=0; i < num_of_vertices; i++) {
        if(i == source)
            cout<<source<<".."<<source;
        else
            printPath(i);
        cout<<"->"<<distances[i]<<endl;
    }

    erfasse_enter();

}
