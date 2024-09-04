#include <iostream>
#include <map>
#include <vector>
#include <list>
using namespace std;

class Graph{

map<int,list<int>> adjList;

public:
    void addEdge(int x, int y){
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }
    int DFS(int node, int a, int b, map<int,bool> &visited){
        visited[node]=true;

        for(int neighbour: adjList[node]){
            if((node == a && neighbour == b) || (node == b && neighbour == a)) continue;
            else if(neighbour == b) return true;
            else if (!visited[neighbour]){
                return DFS(neighbour,a,b,visited);
            }
        }
        return false;
    }
    int dfs(int src, int a, int b){
        map<int,bool> visited;
        return DFS(src,a,b,visited);
    }
};
int main()
{
    Graph g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(0,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    int result=g.dfs(4,4,5);
    cout<<result;
    return 0;
}
