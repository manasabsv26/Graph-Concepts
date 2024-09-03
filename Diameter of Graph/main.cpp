#include <iostream>
#include <map>
#include <list>
#include <queue>

using namespace std;
class Graph{

map<int,list<int>> adjList;

public:

     void addEdge(int x, int y){
     adjList[x].push_back(y);
     adjList[y].push_back(x);
     }

     int bfs(int src){
        map<int,bool> vis;
        queue<pair<int,int>> q;
        int dist;

        vis[src]=true;
        q.push(make_pair(src,0));

        while(!q.empty()){
            pair<int,int> cur=q.front();
            q.pop();
            for(int nbr:adjList[cur.first]){
                if(!vis[nbr]){
                    q.push(make_pair(nbr,cur.second+1));
                    vis[nbr]=true;
                }
            }
            dist=cur.second;
            cout<<"\nVertex: "<<cur.first<<" Distance: "<<dist<<endl;
        }
        return dist;
     }
};
int main()
{
    int nov, *vertices,max_dist=-1;
    cout<<"\n Enter number of vertices";
    cin>>nov;
    vertices = new int[nov];
    cout<<"\n Enter the vertices";
    for(int i=0;i<nov;i++){
        cin>>vertices[i];
    }
    map<int,int> dist_by_src;
    Graph g;
    g.addEdge(0,1);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);

    for(int i=0;i<nov;i++){
        dist_by_src[vertices[i]] = g.bfs(vertices[i]);
        cout<<"\nFor vertex "<<vertices[i]<<" distance is: "<<dist_by_src[i];
        if(dist_by_src[vertices[i]] > max_dist){
            max_dist = dist_by_src[vertices[i]];
        }
    }

    cout<<"\n Diameter of the Graph is: "<<max_dist;

    return 0;
}
