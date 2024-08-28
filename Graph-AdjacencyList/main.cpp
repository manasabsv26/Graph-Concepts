#include <iostream>
#include <list>
#include <cstring>
#include <unordered_map>
using namespace std;

class Graph{

    unordered_map<string, list< pair<string, int> > > l;

public:
    //no constructor needed
    void addEdge(string x, string y, bool bidir, int wt){
        l[x].push_back(make_pair(y, wt));
        if(bidir){
            l[y].push_back(make_pair(x,wt));
        }
    }
    void printAdjList(){
        for( auto item:l){
            //item is a key value pair where key is the source city, and value is list of pairs of dest. cities and wts, [(a,20),(b,50), ...]
            string source = item.first; //key
            list<pair<string, int>> destinations = item.second;
            cout<<source<<": ";
            for(auto destination:destinations){
                cout<<"( "<<destination.first<<", "<<destination.second<<")"<<",";
            }
            cout<<endl;
        }
    }
};

int main()
{
    Graph g;
    g.addEdge("A","B", true, 20);
    g.addEdge("B","D", true, 30);
    g.addEdge("C","D", true, 40);
    g.addEdge("A","C", true, 10);
    g.addEdge("A","D", false, 50);
    g.printAdjList();

    return 0;
}
