#include <iostream>
#include <map>
#include <list>

using namespace std;

template<typename T>
class Graph{

    map<T, list<T>> m;

public:

    void addEdge(T x, T y){
        m[x].push_back(y);
        m[y].push_back(x);
    }

    void printAdjList(){
        for(auto node:m){
            cout<<node.first<<"->";
            for(T nbr:node.second){
                cout<<nbr<<",";
            }
            cout<<endl;
        }

    }

    bool find_cycle(T src){
        map<T, bool> vis;
        bool has_cycle = cycle_helper(src,vis,src);
        return has_cycle;
    }

    bool cycle_helper(T node, map<T,bool> &vis, T parent){  // recursive function to find if there's a cycle

        vis[node] = true;

        for(T nbr:m[node]){
            if(!vis[nbr]){
                //if not visited, traverse - DFS
                bool has_cycle = cycle_helper(nbr,vis,node);
                return has_cycle;
            } else if(nbr!=parent){
                //if it is visited, but not the parent, cycle exists
                return true;
            }
            //search for all vertices
        }
        // if cycle not found will reach here
        return false;
    }

};
int main()
{
    Graph<int> g;
    g.addEdge(1,0);
    g.addEdge(0,4);
    g.addEdge(4,3);
    g.addEdge(3,2);
    g.addEdge(2,1);

    cout<<"Printing Adjacency List"<<endl;
    g.printAdjList();
    cout<<"Is there a cycle? "<<endl;
    bool ans = g.find_cycle(1);
    if (ans){
        cout<<"Yes, graph has a cycle";
    } else {
        cout<<"No, graph does not have a cycle";
    }
    return 0;
}
