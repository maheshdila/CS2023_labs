#include <iostream>

using namespace std;
int V =6; //graph size
void dijkstra(int Graph[6][6], int src) {
    int distance[6];// This is the output array
    bool visited[6]; //once node is being visited here we set visited[i]=true
    for (int i = 0; i < 6; i++) {
        distance[i] = INT_MAX; //each set to infinity
        visited[i] = false; // initially every node was not visited
    }
    distance[src] = 0; // set path length of spurce to 0

    for (int j = 0; j < 5; j++) {
        //now we get the not-visted node with the minimum shortest path
        int current_min = INT_MAX;//infinity
        int min_index;
        for (int k = 0; k < 6; k++) {
            if (visited[k] == false && distance[k] <= current_min) {
                current_min = distance[k];
                min_index = k;
            }
        }
        //===================For vertex with minimum path==================================
        visited[min_index] = true;//marked visited

        for (int v = 0; v < 6; v++) {
            if (!visited[v] && Graph[min_index][v] && distance[min_index] != INT_MAX && distance[min_index] + Graph[min_index][v] < distance[v]) {
                //now we can do the relaxing
                //if ()
                    distance[v] = distance[min_index] + Graph[min_index][v];
            }
        }

    }
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < 6; i++)
        cout << i << " \t\t\t\t" << distance[i] << endl;
    /*double avg;
    int tot=0;
    cout<<"When source city is "<<src<<";"<<endl;
    cout<<"\t the average is, ( ";
    for (int each:distance){
        cout<<each<<"+";
        tot+=each;
    }
    avg = tot/5.0;
    cout<<"\b)/5 = "<<avg;*/

}

int main() {
    int Graph[6][6] = {{0,  10, 0,  0,  15, 5},
                       {10, 0,  10, 30, 0,  0},
                       {0,  10, 0,  12, 5,  0},
                       {0,  30, 12, 0,  0,  20},
                       {15, 0,  5,  0,  0,  0},
                       {5,  0,  0,  20, 0,  0}
    };
    /*for (int i=0;i<6;i++){
        dijkstra(Graph,i);
        cout<<"\n";
    }*/
    dijkstra(Graph,5);
    return 0;

}
