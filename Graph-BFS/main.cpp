#include <iostream>
#include <map>
#include <list>
#include <queue>

using namespace std;
template<typename T> //using template
class Graph{

    map<T, list<T>> m;

public:
    void addEdge(T x,T y){
        m[x].push_back(y);
        m[y].push_back(x);
    }
    void bfs(T src){

        queue<T> q;
        map<T, bool> vis;

        q.push(src);
        cout<<src<<",";
        vis[src]= true;

        while(!q.empty()){
            T node=q.front();
            q.pop();

            for(T nbr:m[node]){
                if(!vis[nbr]){
                    cout<<nbr<<",";
                    vis[nbr]=true;    //first visiting the neighbor
                    q.push(nbr);      //pushing neighbor to the queue
                }
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
    g.bfs(0);
    return 0;
}
