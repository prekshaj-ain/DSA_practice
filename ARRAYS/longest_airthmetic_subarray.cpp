#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
int main(){
    int n;
    cin >> n;
    int A[n],pd=A[1]-A[0],curr = 2,ans = 2;
    for(int i=0 ; i<n ; i++){
        cin >> A[i];
    }
    for(int i=2;i<n;i++){
        if(pd == A[i]-A[i-1]){
            curr++;
        }
        else{
            pd = A[i]-A[i-1];
            curr = 2;
        }
        ans = max(ans,curr);

    }
    cout << "\nAnswer is :"<<ans;
    return 0;

}