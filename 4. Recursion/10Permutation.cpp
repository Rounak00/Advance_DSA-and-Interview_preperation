#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void func(string s, int i=0){
    if(i==s.length()-1){
        cout<<s<<endl;
        return;
    }
    for(int j=i;j<s.length();j++){
        swap(s[i],s[j]);
        func(s, i+1);
        swap(s[j],s[i]);
    }
}

int main(){
    string s="abc";
    func(s);
}