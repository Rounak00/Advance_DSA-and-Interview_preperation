//rec
class Solution {
public:
    int solve(vector<vector<int>>&a,int i, int j){
        if(i>=0 && j>=0 && a[i][j]==1){return 0;} //1 is obstacle here
        if(i==0 && j==0){return 1;}
        if(i<0 || j<0){return 0;}
        
        int left=solve(a,i,j-1);
        int up= solve(a,i-1,j);
         return up+left;   
    }
    int uniquePathsWithObstacles(vector<vector<int>>& a) {
     int i=a.size();
     int j=a[0].size();
        
       return solve(a,i-1,j-1);   
    }
};

//Memoization
class Solution {
public:
    int solve(vector<vector<int>>&a,int i, int j,  vector<vector<int>>&dp){
        if(i>=0 && j>=0 && a[i][j]==1){return dp[i][j]=0;}
        if(i==0 && j==0){return dp[i][j]=1;}
        if(i<0 || j<0){return 0;}
        if(dp[i][j]!=-1){return dp[i][j];}
        int left=solve(a,i,j-1,dp);
        int up= solve(a,i-1,j,dp);
         return dp[i][j]=left+up;   
    }
    int uniquePathsWithObstacles(vector<vector<int>>& a) {
     int i=a.size();
     int j=a[0].size();
        vector<vector<int>>dp(i, vector<int>(j, -1));
       return solve(a,i-1,j-1,dp);   
    }
};

//Tabulation

  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	
        int m = obstacleGrid.size();
        int n= obstacleGrid[0].size();
        vector<vector<int>> dp(m , vector<int>(n , 0));
        
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                }
                else if(i == 0 and j == 0) dp[i][j] = 1;
                else{
                    int up = 0, left = 0;
                    if(i>0) up= dp[i-1][j];
                    if(j >0) left = dp[i][j-1];
                    
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[m-1][n-1];
    }