#include "Dijkstra.h"

Dijkstra::Dijkstra(){};

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

        printf("G\x81nstigste Verbindung von %d nach %d\n", root, x);

        int j = x;

        // Vorgänger verfolgen bis zum Ziel ("Rückwärtssuche")
        while(this->predecessor[j] != 0) {
            printf("%d <- ", j);
            j = this->predecessor[j];
        }

        printf("%d\n\nKosten: %3d\n\n", j, this->distance[x]);
 }
}

/*
#include 



class Dijkstra {



};



// Beispielaufruf

void main() {

  
}

 */