// convert "1234" to 1234.
#include<bits/stdc++.h>
using namespace std;

int convert(char* str){
    if(strlen(str) == 1 ){
        return str[0] - 48;
    }
    
    else{
        int shortAns = convert(str+1);
        double digit = str[0] - 48;
        digit = pow(10,(strlen(str)-1))*digit + shortAns;
        return int(digit);

    }

}

int main(){
    char str[] = "100";
    int output = convert(str);
    cout << output;
    return 0;
}