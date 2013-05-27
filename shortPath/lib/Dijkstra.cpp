#include "Dijkstra.h"

Dijkstra::Dijkstra(){

    unsigned int arr[] = {0,  15, 99999, 99999, 99999, 99999, 99999, 99999, 99999 , 15,   0, 99999,  30,  10, 99999,  25,  10,  30 ,99999, 99999,   0,  20, 99999, 99999,  15, 99999, 99999 ,99999,  30,  20,   0, 99999, 99999, 99999, 99999, 99999 ,99999,  10, 99999, 99999,   0,  40,  10, 99999, 99999 ,99999, 99999, 99999, 99999,  40,   0,  20, 99999, 99999 ,99999,  25,  15, 99999,  10,  20,   0, 99999, 99999 ,99999,  10, 99999, 99999, 99999, 99999, 99999,   0,  10 ,99999,  30, 99999, 99999, 99999, 99999, 99999,  10,   0};
    
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


void Dijkstra::calculate(bool step = false) {

    // Array für markierte Knoten
    bool marked[nodenum];

    // Initialisierung
    for(int x = 0; x < nodenum; ++x) {
        // Kein Knoten ist markiert
        marked[x] = false;

        // Kosten sind zunächst unendlich (99999 = INT_MAX)
        this->distance[x] = 99999;

        // Vorgänger sind nicht vorhanden
        this->predecessor[x] = 0;
    }
 
    // Startknoten besitzt Kosten 0
    this->distance[this->root] = 0;

    bool flag = true;

    while(flag) {
        // minimale Kosten initialisieren
        unsigned int minimum = 99999;

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
            if(!marked[j] && this->intern[node][j] != 0 && this->distance[node] + this->intern[node][j] < this->distance[j]) {
                this->distance[j] = this->distance[node] + this->intern[node][j];
                this->predecessor[j] = node;
            }

            // jeden einzelnen Verbesserungsschritt ausgeben?
            if(step == true)
                (this->distance[j] == 99999) ? printf("INF\t") : printf("%3d\t", this->distance[j]);
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

        printf("Guenstigste Verbindung von %d nach %d\n", root, x);

        int j = x;

        // Vorgänger verfolgen bis zum Ziel ("Rückwärtssuche")
        while(this->predecessor[j] != 0) {
            printf("%d <- ", j);
            j = this->predecessor[j];
        }

        printf("%d\n\nKosten: %3d\n\n", j, this->distance[x]);
 }
}





void Dijkstra::read(){
    numOfVertices = erfasse_int(0,nodenum,"Geben sie die Anzahl der Knoten des Graphen ein:");
    cout<<"Enter the adjacency matrix for the graph\n"<<"To enter infinity enter "<<INFINITY<<endl;
    for(int i=0;i<numOfVertices;i++) {
        cout<<"Enter the (+ve)weights for the row "<<i<<endl;
        for(int j=0;j<numOfVertices;j++) {
            cin>>adjMatrix[i][j];
            while(adjMatrix[i][j]<0) {
                cout<<"Weights should be +ve. Enter the weight again\n";
                cin>>adjMatrix[i][j];
            }
        }
    }
    sources = erfasse_int(0,numOfVertices-1,"Enter the sources vertex\n");
}
 
 
void Dijkstra::initialize(){
    for(int i=0;i<numOfVertices;i++) {
        mark[i] = false;
        predecessor[i] = -1;
        distance[i] = INFINITY;
    }
    distance[sources]= 0;
}
 
 
int Dijkstra::getClosestUnmarkedNode(){
    int minDistance = INFINITY;
    int closestUnmarkedNode;
    for(int i=0;i<numOfVertices;i++) {
        if((!mark[i]) && ( minDistance >= distance[i])) {
            minDistance = distance[i];
            closestUnmarkedNode = i;
        }
    }
    return closestUnmarkedNode;
}
 
 
void Dijkstra::calculateDistance(){
    initialize();
    int minDistance = INFINITY;
    int closestUnmarkedNode;
    int count = 0;
    while(count < numOfVertices) {
        closestUnmarkedNode = getClosestUnmarkedNode();
        mark[closestUnmarkedNode] = true;
        for(int i=0;i<numOfVertices;i++) {
            if((!mark[i]) && (adjMatrix[closestUnmarkedNode][i]>0) ) {
                if(distance[i] > distance[closestUnmarkedNode]+adjMatrix[closestUnmarkedNode][i]) {
                    distance[i] = distance[closestUnmarkedNode]+adjMatrix[closestUnmarkedNode][i];
                    predecessor[i] = closestUnmarkedNode;
                }
            }
        }
        count++;
    }
}
 
 
void Dijkstra::printPath(int node){
    if(node == sources)
        cout<<(char)(node + 97)<<"..";
    else if(predecessor[node] == -1)
        cout<<"No path from “<<sources<<”to "<<(char)(node + 97)<<endl;
    else {
        printPath(predecessor[node]);
        // cout<<(char) (node + 97)<<"..";
        cout<<(char) (node + 97)<<"..";
    }
}
 
void Dijkstra::output(){
    for(int i=0;i<numOfVertices;i++) {
        if(i == sources)
            cout<<(char)(sources + 97)<<".."<<sources;
        else
            printPath(i);
        cout<<"->"<<distance[i]<<endl;
    }

}
