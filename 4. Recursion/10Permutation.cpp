#include<iostream>
#include<string>
#include<algorithm>
using namespace std;


void permute(string a, int l, int r) 
{ 
    if (l == r) 
        cout<<a<<endl; 
    else
    { 
        for (int i = l; i <= r; i++) 
        {
            swap(a[l], a[i]); 
            permute(a, l+1, r);
            swap(a[l], a[i]); 
        } 
    } 
} 
  
 
int main() 
{ 
    string str = "ABC"; 
    int n = str.size(); 
    permute(str, 0, n-1); 
    return 0; 
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