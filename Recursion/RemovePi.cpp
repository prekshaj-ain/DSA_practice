#include <bits/stdc++.h>
using namespace std;

void remove(char str[], int start){
    if(str[start] == '\0' || str[start+1] == '\0'){
        return;
    }
    remove(str,start+1);
    if(str[start]=='p' && str[start+1]=='i'){
        for(int i=strlen(str);i>=start + 2;i--){
            str[i+2] = str[i];
        }
        str[start] = '3';
        str[start+1] = '.';
        str[start+2] = '1';
        str[start+3] = '4';
    }
}

int main(){
    char str[] = "xpipipi";
    remove(str,0);
    cout<< str;
    return 0;
}