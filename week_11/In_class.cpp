#include <iostream>
using namespace std;

int nextMinVertex(int vertices[], bool mstSet[], int size){
    int min = INT_MAX; // set to maximum value that an integer can take
    int min_index ;

    for (int v=0; v< size; v++){
        if (mstSet[v]== false && vertices[v]<min){
            min = vertices[v];
            min_index = v;
        }
    }
    return min_index;
}

void prims(int graph[6][6]){
    int predecessor[6];
    int vertices[6]; //
    bool mstSet[6]; //current mst

    // Initialize all vertices as INFINITE
    for (int i = 0; i < 6; i++)
        vertices[i] = INT_MAX, mstSet[i] = false;

    //set starting node's vertex value to zero
    vertices[0] = 0;
    predecessor[0] = -1; // starting node is the root, so only successors

    for (int i=0; i<(6-1);i++){ // size-1 times running loop
        int u = nextMinVertex(vertices,mstSet,6);
        mstSet[u] = true; // added to current mst

        for (int v=0; v<6; v++){
            if (graph[u][v] !=0 &&   //for non-zero weights
            mstSet[v]==false &&      // if not already in the current mst
            graph[u][v]<vertices[v]  // if the neighbour is lower than the vertices[v]
            ) {
                vertices[v] = graph[u][v];
                predecessor[v] = u;
            }
        }
    }
    //==============graph printing===================
    std :: cout << "Edge \tWeight\n";
    for (int j=1;j<6;j++){
        std:: cout << predecessor[j]<<"-"<<j<<"\t"<<graph[j][predecessor[j]]<<"\n";


    }



}



int main() {

    int graph[6][6]={ {0,3,0,0,0,1 },
                      {3,0,2,1,10,0},
                      {0,2,0,3,0,5},
                      { 0,1,3,0,5,0},
                      {0,10,0,5,0,4},
                      {1,0,5,0,4,0}};

    prims(graph);

    return 0;

}


// Refferences = https://www.geeksforgeeks.org/prims-minimum-spanning-tree-mst-greedy-algo-5/