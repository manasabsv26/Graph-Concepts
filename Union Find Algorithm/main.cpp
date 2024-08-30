#include <iostream>

using namespace std;

class DisjointUnionSets{

    int n;
    int *parent, *ranked;

public:

    DisjointUnionSets(int n){
        this->n=n;
        parent = new int[n];
        ranked = new int[n];
        //Initialize Parent array
        for(int i=0;i<n;i++){
            parent[i]=i;
            ranked[i]=0;
        }
        showParentArray();
        showRankedArray();
    }

    int find_parent(int x){
        if(parent[x]==x){
            return x;
        }

        return find_parent(parent[x]);
    }

    void union_ranked(int x, int y){
        int a=find_parent(x);
        int b=find_parent(y);

        if(ranked[a]<ranked[b]){
            //make b the parent of a
            parent[a]=b;
        } else if(ranked[b]<ranked[a]){
            //make a the parent of b
            parent[b]=a;
        } else {
            //ranks are similar, choose randomly, and increase rank of parent
            parent[b]=a;
            ranked[a]+=1;
        }
        cout<<"\nAdded "<<x<<","<<y<<endl;
        showParentArray();
        showRankedArray();
    }

    void isFriend(int x, int y){
        int rootx=find_parent(x);
        int rooty=find_parent(y);
        cout<<"\n Checking if "<<x<<" and "<<y<<" are friends"<<endl;
        if(rootx == rooty){
            cout<<x<<" and "<<y<<" are friends"<<endl;
        } else {
            cout<<x<<" and "<<y<<" are not friends"<<endl;
        }
    }

    void showParentArray(){
        cout<<"Parent Array:"<<endl;
        for(int i=0;i<n;i++){
            cout<<parent[i]<<" ";
        }
        cout<<endl;
    }

    void showRankedArray(){
        cout<<"Ranked Array:"<<endl;
        for(int i=0;i<n;i++){
            cout<<ranked[i]<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    DisjointUnionSets d(6);
    d.union_ranked(0,1);
    d.union_ranked(2,4);
    d.union_ranked(3,5);
    d.isFriend(0,2);
    d.union_ranked(0,4);
    d.isFriend(0,2);
    return 0;
}
