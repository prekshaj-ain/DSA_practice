//  draw adjacency matrix for a graph
#include<iostream>
using namespace std;
#define V 5
void addedge(int a[][V], int u,int v,bool bidir=true){
    if(bidir){
        a[u][v] = 1;
        a[v][u] = 1;
        return;
    }
    a[u][v]=1;
}
int main(){
    int arr[V][V] ={0};
    addedge(arr, 0,1);
    addedge(arr, 0,2);
    addedge(arr, 0,3);
    addedge(arr, 1,3);
    addedge(arr, 2,3);
    addedge(arr, 3,4);
    cout <<"\nADJACENCY MATRIX\n";
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cout <<arr[i][j]<<" ";
        }
        cout <<endl;
    }
    return 0;
}
