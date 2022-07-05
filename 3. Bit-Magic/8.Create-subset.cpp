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

