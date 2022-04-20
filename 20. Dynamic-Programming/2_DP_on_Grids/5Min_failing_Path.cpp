//Recursion : TC: O(3^n) ~Exponential SC:O(N) ~Stack Space 

class Solution {
public:
    int solve(int i, int j, vector<vector<int>>&a,int n){
        if(j<0||j>n-1){return 1e9; }
        if(i==0){return a[i][j];}
        
        int up=a[i][j]+ solve(i-1,j,a,n);
        int ld=a[i][j]+ solve(i-1,j-1,a,n);
        int rd=a[i][j]+ solve(i-1,j+1,a,n);
        
        return min(up,min(ld,rd));
    }
    int minFallingPathSum(vector<vector<int>>& a) {
        int n=a.size();
        int ans;
        for(int i=0;i<n;i++){
            ans=min(ans,solve(n-1,i,a,n));
        }
        return ans;
    }
};

//Memoization: TC:O(N X N)   SC:O(N)+O(N X N) ~stackSpace+dpArray 
class Solution {
public:
    int solve(int i, int j, vector<vector<int>>&a,int n,vector<vector<int>>&dp){
        if(j<0||j>n-1){return 1e9; }
        if(i==0){return dp[i][j]=a[i][j];}
        if(dp[i][j]!=1e9){return dp[i][j];}
        int up=a[i][j]+ solve(i-1,j,a,n,dp);
        int ld=a[i][j]+ solve(i-1,j-1,a,n,dp);
        int rd=a[i][j]+ solve(i-1,j+1,a,n,dp);
        
        return dp[i][j]=min(up,min(ld,rd));
    }
    int minFallingPathSum(vector<vector<int>>& a) {
        int n=a.size();
        vector<vector<int>>dp(n,vector<int>(n,1e9));
        int ans;
        for(int i=0;i<n;i++){
            ans=min(ans,solve(n-1,i,a,n,dp));
        }
        return ans;
    }
};

//Tabulation : TC:O(N X N) SC:O(N X N)
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>dp(n, vector<int>(n,0));
        
        for(int i=0;i<n;i++){
            dp[0][i]=matrix[0][i];
        }
        
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int up=matrix[i][j]+dp[i-1][j];
                
                int ld=matrix[i][j];
                if(j-1<0)ld=1e9;
                else{ld+=dp[i-1][j-1];}
                
                int rd=matrix[i][j];
                if(j+1>n-1)rd=1e9;
                else{rd+=dp[i-1][j+1];}
                
                dp[i][j]=min(up,min(ld,rd));
            }
        }
        
        int ans;
        for(int i=0;i<n;i++){
            ans=min(ans,dp[n-1][i]);
        }
        return ans;
    }
};