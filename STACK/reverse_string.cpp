#include<iostream>
#include<stack>
using namespace std;
int main(){
    char* ch = new char[51];
    stack<char> S;
    cout << "\nENTER A STRING";
    cin.getline(ch,51);
    int i=0;
    while(ch[i] != '\0'){
        S.push(ch[i]);
        i++;
    }
    i=0;
    while(!S.empty() && ch[i] != '\0'){
       ch[i] = S.top();
       S.pop();
       i++;
    }
    cout << ch;
    return 0;
}
