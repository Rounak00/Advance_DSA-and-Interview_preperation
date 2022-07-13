//Recursion: 2^n X 2^m
//Memoization TC: (MxN) SC:  (MxN)+(M+N)
class Solution {
public:
    int solve(int i,int j, string &a,string &b,vector<vector<int>>&dp){
        if(i<0 ||j<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(a[i]==b[j]){return dp[i][j]= 1+solve(i-1,j-1,a,b,dp);} 
        return dp[i][j]=0+max(solve(i-1,j,a,b,dp),solve(i,j-1,a,b,dp));
    }
   int longestCommonSubsequence(string &a, string &b) {
       int n=a.size();
       int m=b.size();
       vector<vector<int>>dp(n,vector<int>(m,-1));
    return solve(a.size()-1,b.size()-1,a,b,dp);
}
};

//Tabulation SC: MxN
class Solution {
public:
    
   int longestCommonSubsequence(string &a, string &b) {
       int n=a.size();
       int m=b.size();
       vector<vector<int>>dp(n+1,vector<int>(m+1,0));
      
      //here we can write base case as dp[i][0] and dp[0][j] = 0 but we already fill whole dp with 0      
       for(int i=1;i<=n;i++){
           for(int j=1;j<=m;j++){
               if(a[i-1]==b[j-1]){
                   dp[i][j]= 1+dp[i-1][j-1];} 
        else{dp[i][j]=max(dp[i-1][j],dp[i][j-1]);}
           }
       }
       return dp[n][m];
}
};
