#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void func(string s,vector<vector<char>>ans,int i=0){
    if(i==s.length()){
        ans.push_back(s);
        return;
    }
    for(int j=i;j<s.length();j++){
        swap(s[i],s[j]);
        func(s,ans, i+1);
        swap(s[j],s[i]);
    }
}

int main(){
    string s="abc";
    vector<vector<char>>ans;

    func(s,ans, 0);
}

//Naive:
/*

recur(string s,  vector< vector<char>>ans,vector<char>ds,  int freq[] ){
    if(ds.size()==s.length()){ ans.push_back(ds); return ;}
   
   for(int i=0;i<s.length();i++){
       if(!freq[i]){
           freq[i]=1;
           ds.push_back(s[i]);
           recur(s,ans,ds,freq);
           freq[i]=0;
           ds.pop_back();
       }
   }
}
main(string s){
    vector< vector<char>>ans;
    vector<char>ds;
    int freq[s.length()-1]={0};
    return recur(s,ans,ds,freq);
    
}
*/