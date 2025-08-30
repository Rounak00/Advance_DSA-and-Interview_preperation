#include<bits/stdc++.h>
using namespace std;

//2^n subsequences
int main(){
    string x="ABC";
    int n=x.length();
    int subset=1<<n;
    for(int mask=0; mask<subset;mask++){
        for(int i=0;i<n;i++){
            if((mask & (1<<i))!=0){
                cout<<x[i]<<" ";
            }
        }
        cout<<endl;
    }
}

//Assume given is a vector  [1,2,3] TC: O(n*2^n)

int main(){
    vector<int>v={1,2,3};
    int n=v.size();

    int subset=1<<n;
    vector<vector<int>>res;

    for(int m=0;m<subset;m++){
        vector<int>t;
        for(int i=0;i<n;i++){
            if((m&(1<<i))==1){
                t.push_back(v[i]);
            }
        }
        res.push_back(t);
    }
}