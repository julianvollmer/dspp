#include "ShortPath.h"


ShortPath::ShortPath(){

};



void ShortPath::setSource(unsigned int root) {
    this->root = root;
}


void ShortPath::init_random_distances(){
    int size = elements.size();    
    for (vector<Dijkstra>::iterator it = elements.begin() ; it != elements.end(); ++it){
        // cout << ' ' << it->get_name() << endl;
        
        int pos = it->get_position();
        for(int i = 0; i < size && i < pos; i++){
            it->add_distances_to_other(liefere_ganze_zufallszahl(1,250));    
        }
        it->add_distances_to_other(0);
    }
    reflect_to_other_side();

} 

void ShortPath::reflect_to_other_side(){
    int tmp = 0;
    
    
    for (int j = 0; j < elements.size(); j++){
        for(int i = elements[j].get_position()+1; i < elements.size(); i++){
            tmp = elements[i].get_distance_from_specific(j);
            elements[j].add_distances_to_other(tmp);    
        }
    }
    
}

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
}

void ShortPath::print_horizontal_line(){
    for(int i = 0; i < 8*elements.size()+1;i++){
        cout << '*';
    }
    cout << "***";
}

void ShortPath::init_random(){
    // vector<*Dijkstra> sp;

    num_of_vertices = erfasse_int(0,INT_MAX,"Geben Sie die Anzahl der Knoten des Graphen ein:");    
     for(int i = 0; i < num_of_vertices; i++){
        Dijkstra d;
        d.set_distance(0);
        d.set_name(concat_string_and_int("J&P",i));
        d.set_mark(false);
        d.set_predecessor(-1);
        d.set_position(i);
        elements.push_back(d);
     }
        init_random_distances();
}







void ShortPath::init_source(){
     source = erfasse_int(0,num_of_vertices-1,"Enter the source vertex\n");
}


 
 
void ShortPath::initialize(){
    for(int i=0;i<num_of_vertices;i++) {
        elements[i].set_mark(false);
        //predecessor[i] = -1;
        elements[i].set_predecessor(-1);
        distance[i] = INFINITY;
    }
    distance[source]= 0;
}
 
 
int ShortPath::get_closest_unmarked_node(){
    int minDistance = INFINITY;
    int closest_unmarked_node;
    for(int i=0;i<num_of_vertices;i++) {
        if((!elements[i].get_mark()) && ( minDistance >= elements[i].get_distance_from_specific(source))) {
            minDistance = elements[i].get_distance_from_specific(source);
            // cout << minDistance  << "can't be right ?!?!?!" << endl;
            closest_unmarked_node = i;
        }
    }
    return closest_unmarked_node;
}
 
 /**
  * Here is where the magic happens
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
                if(elements[i].get_distance_from_specific(source) > elements[closest_unmarked_node].get_distance_from_specific(source) + elements[closest_unmarked_node].get_distance_from_specific(i)) {
                    elements[i].set_distance(elements[closest_unmarked_node].get_distance_from_specific(source) + elements[closest_unmarked_node].get_distance_from_specific(i));
                    // elements[i].add_distance(elements[closest_unmarked_node].get_distance_from_specific(i));
                    elements[i].set_predecessor(closest_unmarked_node);
                    // cout << "juhu" <<elements[closest_unmarked_node].get_distance_from_specific(i)<< endl;
                    cout << "closest_unmarked_node if " << closest_unmarked_node<<endl;
                }
                
            }
        }
        cout << "closest_unmarked_node not if " << closest_unmarked_node<<endl;
        count++;
    }
}


void ShortPath::show_dk(){
    for (int i = 0; i < num_of_vertices; ++i){
        for (int j = 0; j < num_of_vertices; ++j){
            cout <<"alkfjadsölasd:"<< elements[i].get_distance_from_specific(j) << endl ;
        }
    cout << "next element"<< endl <<endl;    
    }
            
    cout << "get distance()"<<endl <<endl <<endl ;

         for (int i = 0; i < num_of_vertices; ++i){
     
            cout <<"alkfjadsölasd:"<< elements[i].get_distance_from_specific(source) << endl ;
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
        cout<<"->"<<elements[i].get_distance_from_specific(source)<<endl;
    }

}
