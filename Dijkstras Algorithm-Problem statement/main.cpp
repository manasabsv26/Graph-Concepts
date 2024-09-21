#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <utility>
#include <bits/stdc++.h>
using namespace std;

class Graph{

 map<int,list<pair<int,int>>> adjList;

 public:
     void addEdge(int x,int y, int weight){
        adjList[x].push_back({y,weight});
        adjList[y].push_back({x,weight});
     }

     void deleteEdge(int x, int y){
        list<pair<int,int>>::iterator it;
        for(it=adjList[x].begin(); it!=adjList[x].end(); ++it){
            if( (*it).first == y) break;
        }
        adjList[x].erase(it);
        for(it=adjList[y].begin(); it!=adjList[y].end(); ++it){
            if( (*it).first == x) break;
        }
        adjList[y].erase(it);

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

    int Dijkstras(int src,int V, int target){

        priority_queue<pair<int,int>> p;       // priority queue of pair {distance from source, vertex}
        vector<int> dist(V, INT_MAX);          // initial distance from source set to infinity
        dist[src] = 0;
        p.push({0,src});
        while(!p.empty()){
            pair<int,int> node = p.top();
            p.pop();
            for(auto nbr:adjList[node.second]){
                if((dist[node.second] + nbr.second) <dist[nbr.first]){
                    dist[nbr.first] = dist[node.second] + nbr.second;
                    p.push({dist[nbr.first],nbr.first});
                }
            }
        }

        printf("Vertex Distance from Source\n");
        for (int i = 0; i < V; i++){
            cout<<dist[i]<<" ";
        }

        return dist[target];
    }


};

int main()
{
    Graph g;
    int v,src,t, minm =INT_MAX;
    cout<<"\n Enter number of vertices ";
    cin>>v;
    g.addEdge(0,1,8);
    g.addEdge(0,2,5);
    g.addEdge(1,2,9);
    g.addEdge(1,3,11);
    g.addEdge(2,4,10);
    g.addEdge(3,4,7);
    cout << "\nAdjacency list of the graph:\n";
    g.displayGraph();

    cout<<"\n Enter the source vertex: ";
    cin>>src;
    cout<<"\n Enter the target vertex: ";
    cin>>t;
    map<pair<int,int>,int> c;
    pair<int,int> answer;
    int ans_wt;
    c[{1,4}] = 3;
    c[{2,3}] = 10;
    for(auto key:c){
        g.addEdge(key.first.first,key.first.second, key.second);
        g.displayGraph();
        int result = g.Dijkstras(src,v, t);
        cout<<"\n\nS to t shortest: "<<result<<endl;
        if(result < minm){
            minm = result;
            answer ={key.first.first,key.first.second};
            ans_wt = key.second;
        }
        g.deleteEdge(key.first.first,key.first.second);
        cout<<"\n\n";
        g.displayGraph();
    }
    cout<<"\n\nAnswer: "<<answer.first<<", "<<answer.second<<", weight: "<<ans_wt;


}
