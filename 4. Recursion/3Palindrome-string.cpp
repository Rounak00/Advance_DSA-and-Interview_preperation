#include<iostream>
using namespace std;

bool check(string s,int size, int i=0){
    if(i>=size/2){return true;}
    if(s[i]!=s[size-i-1]){return false;}
    check (s,size,i+1);
}

int main(){
    string s="madam";
    int size=5;
    cout<<check(s,size);
}