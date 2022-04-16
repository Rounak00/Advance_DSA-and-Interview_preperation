// REC TC: O(2^mxn) sc: O(path length)
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==0 && n==0){return 1;}
        if(m<0 && n<0){return 0;}
        
        int left=uniquePaths(m,n-1);
        int up=uniquePaths(m-1,n); 
        return left+up;
    }
};
//Memoization TC: O(mxn) SC: O((m-1) + (n-1)) + O(mxn)
class Solution {
public:
    int solve( vector<vector<int>>&dp,int m, int n){
        if(m==0 && n==0){
            return dp[m][n]=1;
        }
        if(m<0 || n<0){
            return 0;
        }
        if(dp[m][n]!=-1){return dp[m][n];}
        
        int left=solve(dp,m,n-1);
        int up=solve(dp,m-1,n);
        return dp[m][n]=left+up;    
    }
    int uniquePaths(int m, int n) {
       vector<vector<int>>dp(m,vector<int>(n,-1));
      return solve(dp, m-1, n-1);
    }
};

//Tabulation TC: O(mxn) SC: O(mxn)
 int uniquePaths(int m, int n) {
     int dp[m][n];
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0||j==0)
                    dp[i][j]=1;
                else
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }