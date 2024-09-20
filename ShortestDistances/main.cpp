#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <utility>
using namespace std;

class Graph{

 map<int,list<pair<int,int>>> adjList;

 public:
     void addEdge(int x,int y, int weight){
        adjList[x].push_back({y,weight});
        adjList[y].push_back({x,weight});
     }

     void displayGraph() {
        for (auto& vertex : adjList) {
            cout << "Vertex " << vertex.first << " -> ";
            for (auto& edge : vertex.second) {
                cout << "( " << edge.first << ", weight: " << edge.second << " ) ";
            }
            cout << endl;
        }
    }

    vector<int> ShortestPath(int src, map<int,int> dis, int target){
        vector<int> path;
        int node;
        node = target;
        map<int,bool> visited;
        visited[node] = true;
        while(node!=src){
            for(auto nbr:adjList[node]){
                if(!visited[nbr.first]){
                    if((dis[nbr.first] + nbr.second) == dis[node]){
                    cout<<nbr.first<<endl;
                    path.push_back(nbr.first);
                    node = nbr.first;
                    }
                }

            }
        }
        return path;
    }

};

int main()
{
    //Problem Statement: Given - Graph G(V,E), source vertex ‘s’, target vertex ‘t’
    //and shortest path distances d(s,u) from source vertex s to all other vertices in G
    //To find the shortest path between s to any target node t
    Graph g;
    int src,tar,v,e;
    vector<int> result;
    map<int,int> dis;
    cout<<"\n Enter number of vertices ";
    cin>>v;
    int vertices[v];
    cout<<"\n Enter the vertices ";
    for(int i=0;i<v;i++){
        cin>>vertices[i];
    }
    cout<<"\n The vertices: ";
    for(int i=0;i<v;i++){
        cout<<vertices[i]<<" ";
    }
    cout<<"\n Enter the source ";
    cin>>src;
    cout<<"\n Enter the target ";
    cin>>tar;
    dis[0]=0;
    dis[1]=8;
    dis[2]=5;
    dis[3]=19;
    dis[4]=15;

    g.addEdge(0,1,8);
    g.addEdge(0,2,5);
    g.addEdge(1,2,9);
    g.addEdge(1,3,11);
    g.addEdge(2,3,15);
    g.addEdge(2,4,10);
    g.addEdge(3,4,7);
    cout << "\nAdjacency list of the graph:\n";
    g.displayGraph();

    result = g.ShortestPath(src,dis,tar);
    cout<<"Path: "<<endl;
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }

}
