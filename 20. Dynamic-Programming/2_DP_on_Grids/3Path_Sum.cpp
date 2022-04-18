//recursion
class Solution {
public:
    int solve(int i, int j, vector<vector<int>>&a){
        if(i==0&&j==0)return a[0][0];
        if(i<0 || j<0)return INT_MAX/2;
        
        int up= a[i][j]+ solve(i-1, j, a);
        int left= a[i][j]+ solve(i,j-1,a);
        
        return min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {      
       int i= grid.size();
        int j=grid[0].size();
        
        return solve(i-1,j-1,grid);
    }
};
//Memoization
class Solution {
public:
    int solve(int i, int j, vector<vector<int>>&a, vector<vector<int>>&dp){
        if(i==0&&j==0)return a[0][0];
        if(i<0 || j<0)return INT_MAX/2;
        if(dp[i][j]!=-1)return dp[i][j];
        int up= a[i][j]+ solve(i-1, j, a,dp);
        int left= a[i][j]+ solve(i,j-1,a, dp);
        
        return dp[i][j]=min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {      
       int i= grid.size();
        int j=grid[0].size();
        vector<vector<int>>dp(i,vector<int>(j,-1));
        return solve(i-1,j-1,grid,dp);
    }
};

//Tabulation
class Solution {
public:
    int minPathSum(vector<vector<int>>& a) {
        int n=a.size();
        int m=a[0].size();
        
        
          vector<vector<int> > dp(n,vector<int>(m,0));
    for(int i=0; i<n ; i++){
        for(int j=0; j<m; j++){
            if(i==0 && j==0) dp[i][j] = a[i][j];
            else{
                
                int up = a[i][j];
                if(i>0) up += dp[i-1][j];
                else up += 1e9;
                
                int left = a[i][j];
                if(j>0) left+=dp[i][j-1];
                else left += 1e9;
                
                dp[i][j] = min(up,left);
            }
        }
    }
    
    return dp[n-1][m-1];
    }
};