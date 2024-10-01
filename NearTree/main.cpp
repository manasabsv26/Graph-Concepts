#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <utility>
#include <bits/stdc++.h>

using namespace std;
struct Edge{
    int st;
    int end;
    int wt;
};

class Graph{


 map<int,list<pair<int,int>>> adjList;
 map<int,bool> visited;
 vector<Edge> st_edges,not_st;
 priority_queue<pair<int,pair<int,int>>> pq;
 vector<pair<int,pair<int,int>>> e;
 vector<pair<int,int>> pnt;
 bool done=false;
 public:

    Graph(int v){
        pnt.resize(v);
    }
     void addEdge(int x,int y, int weight){
        adjList[x].push_back({y,weight});
        adjList[y].push_back({x,weight});
     }

     void deleteEdge(int x, int y, int wt){
        list<pair<int,int>>::iterator it;
        for(it=adjList[x].begin(); it!=adjList[x].end(); ++it){
            if( (*it).first == y && (*it).second == wt ) break;
        }
        adjList[x].erase(it);
        for(it=adjList[y].begin(); it!=adjList[y].end(); ++it){
            if( (*it).first == x && (*it).second == wt) break;
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

    void showSpanningTreeEdges(){

        for(int i=0;i<st_edges.size();i++){
            cout<<st_edges[i].st<<" "<<st_edges[i].end<<" "<<st_edges[i].wt<<endl;
        }
    }
    void showNotInSpanningTreeEdges(){

        for(int i=0;i<not_st.size();i++){
            cout<<not_st[i].st<<" "<<not_st[i].end<<" "<<not_st[i].wt<<endl;
        }
    }

    void DFS(int node, int parent, int wt){
        visited[node] = true;
        st_edges.push_back({parent,node,wt});
        for(auto nbr:adjList[node]){
            if(!visited[nbr.first]){
               int nbr_vertex = nbr.first;
               int nbr_wt = nbr.second;
               DFS(nbr_vertex,node,nbr_wt);
            } else if(nbr.first !=parent){
                not_st.push_back({nbr.first,node,nbr.second});
            }
        }
    }

    vector<Edge> returnSt(){
        return st_edges;
    }
    vector<Edge> returnNotSt(){
        return not_st;
    }

    void DFSCycle(int node, int parent, int wt){
        visited[node] = true;
        pnt[node] = {parent, wt};
        cout<<node<<" "<<parent<<" "<<wt<<endl;
        for(auto nbr:adjList[node]){
            int nbr_vertex = nbr.first;
            int nbr_wt = nbr.second;
            if(!visited[nbr_vertex]){
               DFSCycle(nbr_vertex,node,nbr_wt);
            } else if(nbr_vertex!= parent){
                if(done == true) return;
                cout<<"\nVisited:"<<endl;
                cout<<node<<" "<<nbr_vertex<<" "<<nbr_wt<<endl;
                int curr=node;
                e.push_back({nbr_wt,{node,nbr_vertex}});
                while(curr!=nbr_vertex){
                    int w= pnt[curr].second;
                    int n = pnt[curr].first;
                    e.push_back({w,{n,curr}});
                    curr = n;
                }
                int maxv=INT_MIN, max_index;
                for(int i=0;i<e.size();i++){
                    if(e[i].first > maxv){
                        maxv= e[i].first;
                        max_index=i;
                    }
                }
                pair<int,int> E = e[max_index].second;
                cout<<"\n Deleting max edge: ";
                cout<<E.first<<" "<<E.second<<" "<<e[max_index].first<<endl;
                deleteEdge(E.first,E.second,e[max_index].first);
                done=true;
            }

        }
    }
    void clearpq(int v){
        pq = priority_queue <pair<int,pair<int,int>>>();
        pnt.clear();
        pnt.resize(v);
        visited.clear();
        done=false;
        e.clear();
    }


};

void removeDuplicateWtEdges(std::vector<Edge>& vec_edges) {
    std::unordered_set<int> seen_weights;
    auto it = vec_edges.begin();
    while (it != vec_edges.end()) {
        if (seen_weights.find(it->wt) == seen_weights.end()) {
            // Weight not seen before; keep the edge
            seen_weights.insert(it->wt);
            ++it;
        } else {
            // Duplicate weight; remove the edge
            it = vec_edges.erase(it);
        }
    }
}

int main()
{   Graph g(6);
    g.addEdge(0,1,8);
    g.addEdge(0,2,5);
    g.addEdge(1,2,9);
    g.addEdge(1,3,3);
    g.addEdge(2,4,10);
    g.addEdge(3,4,7);
    g.addEdge(0,5,6);
    g.addEdge(1,4,15);
    vector<Edge> edges = {
        {0, 1, 8}, {0, 2, 5}, {1, 2, 9}, {1, 3, 3}, {2, 4, 10},{3,4,7},{0,5,6}, {1,4,15}
    };
    g.DFS(0,0,0);
    g.showSpanningTreeEdges();
    cout<<"\nNot in spanning tree edges: "<<endl;
    g.showNotInSpanningTreeEdges();
    vector<Edge> stree = g.returnSt();
    vector<Edge> not_st = g.returnNotSt();
    removeDuplicateWtEdges(not_st);

    cout<<"\nDisplay NOT_ST edges after removing duplicates: "<<endl;
    for (Edge& e : not_st)
        cout << "Edge " << e.st << " - " << e.end << " with cost " << e.wt << endl;

    Graph g1(6);
    for(int i=1;i<stree.size();i++){
        g1.addEdge(stree[i].st,stree[i].end,stree[i].wt);
    }
    cout<<"\nDisplay Spanning Tree: "<<endl;
    g1.displayGraph();

    //Add each edge and find the MST
    for(int i=0;i<not_st.size();i++){
        g1.addEdge(not_st[i].st, not_st[i].end, not_st[i].wt);
        cout<<"\nDisplay graph after adding edge: "<<endl;
        g1.displayGraph();
        g1.clearpq(6);
        g1.DFSCycle(not_st[i].st, not_st[i].st,0);
        cout<<"\nDisplay graph after one iteration: "<<endl;
        g1.displayGraph();
        cout<<"===================================="<<endl;
    }
    cout<<"\nDisplay Minimum Spanning Tree: "<<endl;
    g1.displayGraph();
    //for (Edge& e : edges)
        //cout << "Edge " << e.u << " - " << e.v << " with cost " << e.cost << endl;

}
