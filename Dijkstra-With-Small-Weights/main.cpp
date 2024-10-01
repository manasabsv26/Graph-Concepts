#include <iostream>
#include <list>
#include <vector>
using namespace std;
class Graph{

vector<list<pair<int,int>>> adjList;
vector<int> dist;
//map<int,bool>

public:

    void addEdge(int x, int y, int wt){
        adjList[x].push_back({y,wt});
        //adjList[y].push_back({x,wt});
    }

    Graph(int v){
        dist.resize(v,INT_MAX);
        adjList.resize(v);
    }

    vector<int> Dijkstras(int src, int w, int v){

        dist[src]=0;
        vector<list<int>::iterator> positions(v);
        int c = v*w+1;

        vector<list<int>> s_distances(c);
        s_distances[0].push_back(src);
        positions[src] == --s_distances[0].end();

        int i=0;
        while(i<c){
            if(s_distances[i].empty()){
                i++;
                continue;
            }
            int u=s_distances[i].front();
            s_distances[i].pop_front();
            //positions[u] = list<int>::iterator();
            cout<<"\n u"<<u<<endl;

            for(auto nbr: adjList[u]){
                int v=nbr.first;
                int wt=nbr.second;
                cout<<"\n v,wt "<<v<<" "<<wt<<endl;
                int wt_from_src = dist[u] + wt;
                if( wt_from_src < dist[v]){
                    if(dist[v]!=INT_MAX){
                        s_distances[dist[v]].erase(positions[v]);
                    }
                    dist[v] = wt_from_src;
                    s_distances[wt_from_src].push_back(v);
                    positions[v] = --s_distances[wt_from_src].end();
                }

            }
        }
        return dist;
    }

};
int main()
{
    Graph g(5);
    g.addEdge(0,1,2);
    g.addEdge(0,2,4);
    g.addEdge(1,2,1);
    g.addEdge(1,3,7);
    g.addEdge(3,4,1);
    g.addEdge(2,4,3);
    g.addEdge(1,4,6);
     cout<<"hi"<<endl;
    vector<int> shortest_distances = g.Dijkstras(0,8,5);
    for(int i=0;i<shortest_distances.size();i++){
        cout<<i<<" "<<shortest_distances[i]<<endl;
    }

    return 0;
}
