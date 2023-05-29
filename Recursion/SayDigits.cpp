#include<bits/stdc++.h>
using namespace std;
void dispatcher(int &num, string arr[10]){
    if(num==0) {
        return;
    }
    int digit = num %10;
    num = num/10;
    dispatcher(num,arr);
    cout << arr[digit];
}
int main(){
    string arr[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    int num = 100;
    dispatcher(num, arr);
}