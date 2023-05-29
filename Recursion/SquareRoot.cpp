#include<bits/stdc++.h>
using namespace std;
int SquareRoot(int low, int high, int num){
    if(num < 2) return num;
    if(low > high) return low;
    int mid = high - (high - low)/2;
    if((mid*mid <= num) && (((mid+1)*(mid+1)) > num)) return mid;
    else if(mid*mid > num) return SquareRoot(low,mid-1,num);
    else return SquareRoot(mid+1,high,num);
}
int main(){
    int num = 25;
    cout << SquareRoot(0,num,num);
    return 0;
}