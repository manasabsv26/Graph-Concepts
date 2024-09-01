#include <iostream>
#include <map>
#include <stack>
#include <list>
#include <vector>
#include <queue>

using namespace std;
template<typename T>
class Graph{

    map<T,list<T>> m;

public:

    void addEdge(int x,int y){
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

    void bfsTopologicalSort(vector<int> v){
        map<T,int> indegree;
        queue<T> q;

        for(int i=0;i<v.size();i++){
            indegree[v[i]]=0;
        }

        for(auto node:m){
            for(auto nbr:node.second){
                indegree[nbr]++;
            }
        } //Created the inDegree vector

        cout<<"\nIndegree vector: ";
        for(int i=0;i<indegree.size();i++){
            cout<<indegree[i]<<" ";
        }


        for(auto node:indegree){
            if(indegree[node.second]==0) q.push(node.first);
        }

        cout<<"\nTopological Sort: ";
        while(!q.empty()){
            T cur=q.front();
            q.pop();
            cout<<cur<<",";
            for(T nbr:m[cur]){
                if(--indegree[nbr]==0){
                    q.push(nbr);
                }
            }

        }

    }
};
int main()
{
    Graph<int> g;
    int nov,v;
    vector<int> vertices;
    cout<<"\nEnter number of vertices: ";
    cin>>nov;
    cout<<"\nEnter the vertices: ";
    for(int i=0;i<nov;i++)
    {
        cin>>v;
        vertices.push_back(v);
    }
    g.addEdge(0,2);
    g.addEdge(2,3);
    g.addEdge(3,1);
    g.addEdge(2,1);
    g.addEdge(5,1);
    g.addEdge(1,4);
    g.addEdge(5,4);
    g.printAdjList();
    g.bfsTopologicalSort(vertices);
    return 0;
}
