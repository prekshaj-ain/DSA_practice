#include<iostream>
#include<map>
#include<queue>
#include<string>
#include<list>
using namespace std;
template<typename T>
class Graph{
    map<T,list<T>> l;
    public:
    void addedge(T u,T v){
        l[u].push_back(v);
        l[v].push_back(u);
    }
    void bfs(T src){
        map<T,bool> visited;
        queue<T> q;

        q.push(src);
        visited[src] = true;
        while(!q.empty()){
            T node = q.front();
            cout << node<< " ";
            q.pop();
            for(auto nbr: l[node]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr] = true;
                }
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
    g.bfs("A");

}