//Rec   TC:
class Solution {
public:
    int solve(int i, int j,vector<vector<int>>&a, int n){
        if(i==n-1){return a[i][j];}
        
        int down= a[i][j]+solve(i+1,j,a,n);
        int di=a[i][j]+solve(i+1,j+1,a,n);
        
        return min(down,di);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
      int n=triangle.size();
        return solve(0,0,triangle,n);
}
};
//Memo
class Solution {
public:
    int solve(int i, int j,vector<vector<int>>&a, int n,vector<vector<int>>&dp){
        if(i==n-1){return dp[i][j]= a[i][j];}
        if(dp[i][j]!=-1){return dp[i][j];}
        int down= a[i][j]+solve(i+1,j,a,n,dp);
        int di=a[i][j]+solve(i+1,j+1,a,n,dp);
        
        return dp[i][j]=min(down,di);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
      int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(0,0,triangle,n,dp);
}
};
//tabulation
class Solution {
public:
  
    int minimumTotal(vector<vector<int>>& a) {
      int n=a.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
     for(int j=0;j<n;j++){
         dp[n-1][j]=a[n-1][j];
     }      
        
     for(int i=n-2;i>=0;i--){
         for(int j=i;j>=0;j--){
             int dow=a[i][j]+dp[i+1][j];
             int di=a[i][j]+dp[i+1][j+1];
             
             dp[i][j]=min(dow,di);
         }
     }   
        return dp[0][0];
}
};

// NB: wheneever we do recursion bottom to up tabulation will be top down
