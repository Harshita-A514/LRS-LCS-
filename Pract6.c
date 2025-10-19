#include <stdio.h>
#include <stdlib.h>
#include <float.h>

#define  MAX_V 50
#define MAX_E 100

typedef struct Graph{
   int  source, dest;
   int cost;
}Graph;

void bellman(Graph g[MAX_E],int V, int E,int src){
int dist[MAX_V];
    for(int i = 0; i<V; i++){
        dist[i]=__INT_MAX__;
    }

    dist [src]= 0;

    for(int i=1; i<V-1; i++){
        for(int j=0; j<E; j++){
            int u = g[j].source;
            int v = g[j].dest;
            int w = g[j].cost;
        
            if(dist[u] != __INT_MAX__ && dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
            }
        }
    }

    for(int j=0; j<E; j++){
            int u = g[j].source;
            int v = g[j].dest;
            int w = g[j].cost;
        
            if(dist[u] != __INT_MAX__ && dist[u] + w < dist[v]){
                printf("NEGATIVE WEIGHT CYCLE DETECTED\n");
            }
        }


        printf("Shortest distance from Zero Mile (Node %d)\n",src);
        for(int i= 0; i <V; i++){
            if(dist[i]==__INT_MAX__)
               printf("To node %d : INF\n",i);
            else
               printf("To node %d : %d km\n",i,dist[i]);
        }
}

int main(){
    /* 0 - Zero Mile (Pickup Point)
       1 - Sitabuldi
       2 - Dharampeth
       3 - Sadar
       4 - Civil Lines
       5 - Itwari
       6 - Mankapur
    */

    int V = 7;  
    int E = 16; 

    Graph g[MAX_E] = {
        {0,1,2}, {1,0,2},
        {0,2,3}, {2,0,3},
        {0,3,4}, {3,0,4},
        {1,2,1}, {1,3,2},
        {2,4,2}, {4,2,2},
        {3,4,3}, {3,5,5},
        {4,5,2}, {5,6,3},
        {2,6,4}, {6,0,6}
    };

    int src = 0; // Zero Mile as source
    bellman(g,V,E,src);

    return 0;
}
