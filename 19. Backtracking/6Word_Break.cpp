 
//THIS SOLUTION CAN BE OPTIMIZED USING DYNAMIC PROGRAMMING
//WILL DISCUSS THE OPTIMIZED APPROACH, WHEN I WILL START DP PLAYLIST
//AS OF NOW, ONLY DISCUSSED THE BACKTRACKING APPROCH

#include<bits/stdc++.h>
using namespace std;

bool wordBreakUtil(int i,int j, int n, string &A, vector<string> &B){
    if(j == n){
        if(i == n) return true;
        return false;
    }

    if(find(B.begin(), B.end(), A.substr(i,j-i+1)) == B.end()){
        return wordBreakUtil(i,j+1,n,A,B);
    }
    else{
        if(wordBreakUtil(i,j+1,n,A,B)) return true;
        return wordBreakUtil(j+1,j+1,n,A,B);
    }
}
int wordBreak(string A, vector<string> &B) {
    return wordBreakUtil(0,0,A.size(),A,B);   
}