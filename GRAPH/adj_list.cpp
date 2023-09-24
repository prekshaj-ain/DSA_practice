#include<iostream>
#include<list>
using namespace std;
#define V 5
list<int> *l = new list<int>[V];
void addedge(int u,int v){
    l[u].push_back(v);
    l[v].push_back(u);
}

int main(){
    addedge(0,1);
    addedge(0,2);
    addedge(0,3);
    addedge(1,3);
    addedge(2,3);
    addedge(3,4);
    for(int i=0;i<V;i++){
        cout <<"Vertex "<<i<<"->";
        for(int nbr:l[i]){
            cout<<nbr<<",";
        }
        cout <<endl;
    }
    return 0;
}