#include <iostream>
#include <map>
#include <list>
using namespace std;

template<typename T>
class Graph{

    map<T,list<T>> m;

public:

    void addEdge(T x,T y){
        m[x].push_back(y);
        m[y].push_back(x);
    }

    void printAdjList(){
        for(auto node:m){
            cout<<node.first<<"->";
            for(auto nbr:node.second){
                cout<<nbr<<",";
            }
            cout<<endl;
        }

    }

    void dfs(T src){

        map<T,bool> vis;
        dfs_helper(src, vis);
    }

    void dfs_helper(T src, map<T,bool> &vis){
        cout<<src<<",";
        vis[src]=true;

        for(T nbr:m[src]){  // iterating over neighbors of src, present as a list in m[src]
            if(!vis[nbr]){
                dfs_helper(nbr, vis);
            }
        }
    }

};
int main()
{
    Graph<int> g; //NOTE the syntax Graph<int> to give the template type
    g.addEdge(0,1);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    cout<<"Printing Adjacency List"<<endl;
    g.printAdjList();
    cout<<"Depth First Search:"<<endl;
    g.dfs(0);
    return 0;
}
