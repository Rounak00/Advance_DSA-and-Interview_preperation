//Recursion:
class Solution {
public:
   
    int solve(int r1,int c1, int c2,vector<vector<int>>&a, int n,vector<vector<vector<int>>>&dp){
        int r2=r1+c1-c2;
        if(r1>=n||r2>=n||c1>=n||c2>=n||a[r1][c1]==-1||a[r2][c2]==-1){return -1e9;}
        
        
        if(r1==n-1&&c1==n-1){return a[r1][c1];}
        
        int ans=a[r1][c1];
        if(c1!=c2)ans+=a[r2][c2];
        int temp=max(solve(r1,c1+1,c2+1,a,n,dp),solve(r1+1,c1,c2,a,n,dp));
        temp=max(temp,solve(r1,c1+1,c2,a,n,dp));
        temp=max(temp,solve(r1+1,c1,c2+1,a,n,dp));
        ans+=temp;
        return ans;
        
    }
    int cherryPickup(vector<vector<int>>& a) {
       vector<vector<vector<int>>>dp(51,vector<vector<int>>(51,vector<int>(51,-1)));
        int n=a.size();
        return max(0,solve(0,0,0,a,n,dp));
    }
};

//Memoization: TC: O(N X N X N)*4 sc:O(N) + O(50+50+0) 
class Solution {
public:
   
    int solve(int r1,int c1, int c2,vector<vector<int>>&a, int n,vector<vector<vector<int>>>&dp){
        int r2=r1+c1-c2;
        if(r1>=n||r2>=n||c1>=n||c2>=n||a[r1][c1]==-1||a[r2][c2]==-1){return -1e9;}
        
        if(dp[r1][c1][c2]!=-1){return dp[r1][c1][c2];}
        if(r1==n-1&&c1==n-1){return a[r1][c1];}
        
        int ans=a[r1][c1];
        if(c1!=c2)ans+=a[r2][c2];
        int temp=max(solve(r1,c1+1,c2+1,a,n,dp),solve(r1+1,c1,c2,a,n,dp));
        temp=max(temp,solve(r1,c1+1,c2,a,n,dp));
        temp=max(temp,solve(r1+1,c1,c2+1,a,n,dp));
        ans+=temp;
        return dp[r1][c1][c2]=ans;
        
    }
    int cherryPickup(vector<vector<int>>& a) {
       vector<vector<vector<int>>>dp(51,vector<vector<int>>(51,vector<int>(51,-1)));
        int n=a.size();
        return max(0,solve(0,0,0,a,n,dp));
    }
};