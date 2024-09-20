#include <iostream>
#include <map>
#include <vector>
#include <list>

using namespace std;

class Graph{
    map<int,list<int>> adjList;
    map<pair<int,int>, int> counting;

public:

    void addEdge(int x, int y){
        adjList[x].push_back(y);
    }

    bool dfs(int src,int node, map<int,bool> visited){
        visited[node]=true;
        if (++counting[make_pair(src,node)] > 1)
        {
            cout<<src<<"-> "<<node<<"-> "<<counting[make_pair(src,node)]<<endl;
            return false;
        }
        cout<<src<<"-> "<<node<<"-> "<<counting[make_pair(src,node)]<<endl;
        for(int nbr:adjList[node]){
            if(!visited[nbr]){
                if (!dfs(src, nbr, visited)) {
                    return false;
                }
            }
        }

        return true;
    }

    bool dfs_helper(int src){
        map<int,bool> visited;
        return dfs(src,src, visited);
    }
};

int main()
{
    Graph g;
    int nov,*vertices,i;
    g.addEdge(1,2);
    g.addEdge(2,4);
    g.addEdge(4,6);
    g.addEdge(6,2);
    g.addEdge(1,3);
    g.addEdge(3,5);
    g.addEdge(5,7);
    g.addEdge(5,8);
    g.addEdge(1,8);
    cout<<"\n Enter number of vertices";
    cin>>nov;
    vertices = new int[nov];
    for(i=0;i<nov;i++){
        cin>>vertices[i];
    }
    for(i=0;i<nov;i++){
        cout<<"\n\n For vertex: "<<vertices[i]<<endl;
        bool result = g.dfs_helper(vertices[i]);
        if(result == false){
            cout<<"It is not a singly connected graph";
            break;
        }
    }
    if (i==nov){
        cout<<"It is a singly connected graph";
    }
    return 0;
}
