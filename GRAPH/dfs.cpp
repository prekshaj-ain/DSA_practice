#include<iostream>
#include<map>
#include<string>
#include<list>
#include<stack>
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
       stack<T> s;
       s.push(src);
       visited[src] = true;
       while(!s.empty()){
           T v = s.top();
           s.pop();
           cout << v << " ";
           for(auto nbr:l[v]){
               if(!visited[nbr]){
                   s.push(nbr);
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
    g.dfs("A");

}