#include <iostream>
#include <map>
#include <stack>
#include <list>
#include <vector>
using namespace std;

template<typename T>
class Graph{

    map<T,list<T>> m;

public:

    void addEdge(int x, int y){
        m[x].push_back(y);
    }
    void printAdjList(){

        cout<<"\nAdjacency List: ";
        for(auto node:m){
            cout<<node.first<<"->";
            for(T nbr:node.second){
                cout<<nbr<<",";
            }
            cout<<endl;
        }
    }
    void topologicalSort(){
        map<T,bool> vis;
        stack<T> st;
        vector<T> ans;

        for(auto vertex:m){
            if(!vis[vertex.first]){
                dfs(vertex.first,vis,st);
            }
        }

        while(!st.empty()){
            cout<<st.top()<<",";
            st.pop();
        }

    }

    void dfs(T node, map<T,bool> &vis,stack<T> &st){

        vis[node] = true;
        for(T nbr:m[node]){
            if(!vis[nbr]){
                dfs(nbr,vis,st);
            }
        }

        st.push(node);
    }
};

int main()
{
    Graph<int> g;
    g.addEdge(0,2);
    g.addEdge(2,3);
    g.addEdge(3,1);
    g.addEdge(2,1);
    g.addEdge(5,1);
    g.addEdge(1,4);
    g.addEdge(5,4);
    g.printAdjList();
    g.topologicalSort();
    return 0;
}
