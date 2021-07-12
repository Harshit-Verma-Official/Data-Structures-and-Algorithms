#include<bits/stdc++.h>
 
#define V 4
 
using namespace std;
 
int countTriangle(int graph[V][V],
                  bool isDirected)
{
    int count_Triangle = 0;
 
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            for (int k = 0; k < V; k++)
            {
               if (graph[i][j] && graph[j][k]
                               && graph[k][i])
                  count_Triangle++;
             }
        }
    }
 
    isDirected? count_Triangle /= 3 :
                count_Triangle /= 6;
 
    return count_Triangle;
}
 
int main()
{
    int graph[][V] = { {0, 1, 1, 0},
                       {1, 0, 1, 1},
                       {1, 1, 0, 1},
                       {0, 1, 1, 0}
                     };
 
    int digraph[][V] = { {0, 0, 1, 0},
                        {1, 0, 0, 1},
                        {0, 1, 0, 0},
                        {0, 0, 1, 0}
                       };
 
    cout << "The Number of triangles in undirected graph : "
         << countTriangle(graph, false);
    cout << "\n\nThe Number of triangles in directed graph : "
         << countTriangle(digraph, true);
 
    return 0;
}