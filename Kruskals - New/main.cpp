#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
class Edge
{
public:

    T src;
    T dest;
    int wt;

    bool operator<(const Edge &e) const {
        return wt < e.wt;
    }
};

template<typename T>
class DisjointSets{

    int n;
    map<T,T> parent;
    map<T,int> ranked;

public:

    DisjointSets(vector<string> v){
        for(int i=0;i<v.size();i++){
            parent[v[i]]= v[i];
            ranked[v[i]] = 0;
        }
    }
    T find_parent(T x){
        if(parent[x]==x){
            return x;
        }

        return find_parent(parent[x]);
    }

    bool unionize(T x,T y){
        T rootx = find_parent(x);
        T rooty = find_parent(y);

        if(rootx == rooty) return false;
        else if(ranked[rootx] < ranked[rooty]){
            parent[rootx] = rooty;
        } else if(ranked[rooty] < ranked[rootx]){
            parent[rooty] = rootx;
        } else {
            //rank is similar
            parent[rooty] = rootx;
            ranked[rootx]+=1;
        }
        return true;
    }

    void Kruskal(vector<Edge<string>> e){

        sort(e.begin(),e.end());
        vector<Edge<string>> result;
        int ans;
        bool union_done;

        for(int i=0;i<e.size();i++){
            union_done=unionize(e[i].src,e[i].dest);
            if(union_done){
                ans+=e[i].wt;
                result.push_back(e[i]);
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
{
    Edge<string> temp;
    vector<Edge<string>> edges;  //note this syntax
    vector<string> vertices;
    string temp_str;

    int no_edges,no_vertices;
    cout<<"Enter number of edges ";
    cin>>no_edges;
    cout<<"Enter no. of vertices ";
    cin>>no_vertices;
    cout<<"Enter the vertices";
    for(int i=0;i<no_vertices;i++){
        cin>>temp_str;
        vertices.push_back(temp_str);
    }

    DisjointSets<string> d(vertices);

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
