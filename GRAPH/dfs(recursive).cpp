#include<iostream>
#include<map>
#include<string>
#include<list>
using namespace std;
template<typename T>
class Graph{
    map<T,list<T>> l;
    map<T,bool> visited;
    public:
    void addedge(T u,T v){
        l[u].push_back(v);
        l[v].push_back(u);
    }
    void dfs(T src){
        visited[src] = true;
        cout << src <<" ";
        for(auto nbr:l[src]){
            if(!visited[nbr]){
                dfs(nbr);
            }
            
        }
    }
};
int main(){
    Graph<string> g;
    g.addedge("A","B");
    g.addedge("A","C");
    g.addedge("A","D");
    g.addedge("C","D");
    g.addedge("B","D");
    g.addedge("D","E");
    g.dfs("A");

}