#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Edge{

public:

    int src;
    int dest;
    int wt;
     // Overloading < operator
    bool operator<(const Edge& edge) const
    {
        return wt < edge.wt;
    }

};

class DisjointUnionSets{

    int n, *parent, *ranked;

public:

    DisjointUnionSets(int n){
        this->n=n;
        parent = new int[n];
        ranked = new int[n];

        for(int i=0;i<n;i++){
            parent[i] = i;
            ranked[i] = 0;
        }
    }

    void showParent(){
        cout<<"Parent Array:"<<endl;
        for(int i=0;i<n;i++){
            cout<<parent[i]<<" ";
        }
        cout<<endl;
    }

    void showRanked(){
        cout<<"Ranked Array:"<<endl;
        for(int i=0;i<n;i++){
            cout<<ranked[i]<<" ";
        }
        cout<<endl;
    }

    int find_parent(int x){

        if(parent[x]==x){
            return x;
        }

        return find_parent(parent[x]);
    }

    bool unionize(int x,int y){ // returns true if it did perform a union operation. Returns false if x & y are in the same set and so union wasn't performed.
        int rootx=find_parent(x);
        int rooty=find_parent(y);

        if( rootx == rooty) return false;
        else if (ranked[rootx] < ranked[rooty]){
            parent[rootx]=rooty;
        } else if(ranked[rooty] < ranked[rootx]){
            parent[rooty]=rootx;
        } else {
            parent[rooty]=rootx;
            ranked[rootx]+=1;
        }
        return true;
    }

    void Kruskal(vector<Edge> e){

        sort(e.begin(),e.end());

        vector<Edge> result;
        int ans=0;
        for(int i=0;i<e.size();i++){
            bool union_done=unionize(e[i].src,e[i].dest);
            if(union_done) {
                result.push_back(e[i]);
                ans+=e[i].wt;
            }
        }

        cout<<"\nTotal weight of MST: "<<ans;
        cout<<"\nEdges of MST: ";
        for(int i=0;i<result.size();i++){
            cout<<"("<<result[i].src<< " ,"<<result[i].dest<<")";
            cout<<endl;
        }
    }
};

int main()
{   vector<Edge> edges;
    Edge temp;
    int no_edges,no_vertices;
    cout<<"Enter number of edges ";
    cin>>no_edges;
    cout<<"Enter no. of vertices ";
    cin>>no_vertices;

    DisjointUnionSets d(no_vertices);

    for(int i=0;i<no_edges;i++){
        cout<<"Edge "<<i<<": ";
        cout<<"\nEnter src: ";
        cin>>temp.src;
        cout<<"Enter destination: ";
        cin>>temp.dest;
        cout<<"Enter weight: ";
        cin>>temp.wt;

        edges.push_back(temp);
    }

    d.Kruskal(edges);
    return 0;
}
