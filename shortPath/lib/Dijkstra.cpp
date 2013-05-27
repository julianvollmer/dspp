#include "Dijkstra.h"


Dijkstra::Dijkstra(){

    unsigned int arr[] = {0,  15, 9999999, 9999999, 9999999, 9999999, 9999999, 9999999, 9999999 , 15,   0, 9999999,  30,  10, 9999999,  25,  10,  30 ,9999999, 9999999,   0,  20, 9999999, 9999999,  15, 9999999, 9999999 ,9999999,  30,  20,   0, 9999999, 9999999, 9999999, 9999999, 9999999 ,9999999,  10, 9999999, 9999999,   0,  40,  10, 9999999, 9999999 ,9999999, 9999999, 9999999, 9999999,  40,   0,  20, 9999999, 9999999 ,9999999,  25,  15, 9999999,  10,  20,   0, 9999999, 9999999 ,9999999,  10, 9999999, 9999999, 9999999, 9999999, 9999999,   0,  10 ,9999999,  30, 9999999, 9999999, 9999999, 9999999, 9999999,  10,   0};
    
    int j,k = 0;
    
    for(int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++){
     
            this->intern[j][k] = arr[i];
            k++;
            if(i == nodenum){
                j++;
                k = 0;
            }
    }
};



void Dijkstra::setSource(unsigned int root) {
    this->root = root;
}


void Dijkstra::setMatrix(unsigned int matrix[nodenum][nodenum]) {
    memcpy(this->intern, matrix, nodenum * nodenum * sizeof(unsigned int));
}


void Dijkstra::get(unsigned int (*&retVal)[nodenum][nodenum]){
    retVal = &intern;
}

void Dijkstra::add_random_row(){

}

void Dijkstra::init_random(){
    num_of_vertices = erfasse_int(0,INT_MAX,"Geben Sie die Anzahl der Knoten des Graphen ein:");

    for(int i=0;i<num_of_vertices;i++) {
        // add_random_row();
        for(int j=0;j<num_of_vertices;j++) {
            if(1!=liefere_ganze_zufallszahl(0,num_of_vertices/10)){
                adjMatrix[i][j] = INFINITY;
                adjMatrix[j][i] = INFINITY;
            }
            else{
                int tmp = liefere_ganze_zufallszahl(7,200);
                adjMatrix[i][j] = tmp;
                adjMatrix[j][i] = tmp;    
            }  
        }
    }

    for(int i = 0; i < num_of_vertices; i++){
        adjMatrix[i][i] = 0;
    }
}




void Dijkstra::print(){
    for(int i = 0; i < num_of_vertices;i++){
        for(int j = 0; j < num_of_vertices;j++){
            if (adjMatrix[i][j] == 2147483647)
                cout << "INF" << '\t';  
            else
                cout << adjMatrix[i][j] << '\t';
        }   
        cout << endl; 
    }
}


void Dijkstra::read(){
    num_of_vertices = erfasse_int(0,nodenum,"Geben sie die Anzahl der Knoten des Graphen ein:");
    cout<<"Enter the adjacency matrix for the graph\n"<<"To enter infinity enter "<<INFINITY<<endl;
    for(int i=0;i<num_of_vertices;i++) {
        cout<<"Enter the (+ve)weights for the row "<<i<<endl;
        for(int j=0;j<num_of_vertices;j++) {
            cin>>adjMatrix[i][j];
            while(adjMatrix[i][j]<0) {
                cout<<"Weights should be +ve. Enter the weight again\n";
                cin>>adjMatrix[i][j];
            }
        }
    }
    init_source();  
}


void Dijkstra::init_source(){
     source = erfasse_int(0,num_of_vertices-1,"Enter the source vertex\n");
}


 
 
void Dijkstra::initialize(){
    for(int i=0;i<num_of_vertices;i++) {
        mark[i] = false;
        predecessor[i] = -1;
        distance[i] = INFINITY;
    }
    distance[source]= 0;
}
 
 
int Dijkstra::get_closed_unmarked_node(){
    int minDistance = INFINITY;
    int closest_unmarked_node;
    for(int i=0;i<num_of_vertices;i++) {
        if((!mark[i]) && ( minDistance >= distance[i])) {
            minDistance = distance[i];
            closest_unmarked_node = i;
        }
    }
    return closest_unmarked_node;
}
 
 
void Dijkstra::calculate_distance(){
    initialize();
    int minDistance = INFINITY;
    int closest_unmarked_node;
    int count = 0;
    while(count < num_of_vertices) {
        closest_unmarked_node = get_closed_unmarked_node();
        mark[closest_unmarked_node] = true;
        for(int i=0;i<num_of_vertices;i++) {
            if((!mark[i]) && (adjMatrix[closest_unmarked_node][i]>0) ) {
                if(distance[i] > distance[closest_unmarked_node]+adjMatrix[closest_unmarked_node][i]) {
                    distance[i] = distance[closest_unmarked_node]+adjMatrix[closest_unmarked_node][i];
                    predecessor[i] = closest_unmarked_node;
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
void Dijkstra::printPath(int node){
    if(node == source)
        cout<<(char)(node + 97)<<"..";
    else if(predecessor[node] == -1)
        cout<<"No path from “<<source<<”to "<<(char)(node + 97)<<endl;
    else {
        printPath(predecessor[node]);
        cout<<(char) (node + 97)<<"..";
    }
}
 /**
  * print the output on the console
  */
void Dijkstra::output(){
    for(int i=0;i<num_of_vertices;i++) {
        if(i == source)
            cout<<(char)(source + 97)<<".."<<source;
        else
            printPath(i);
        cout<<"->"<<distance[i]<<endl;
    }

}
