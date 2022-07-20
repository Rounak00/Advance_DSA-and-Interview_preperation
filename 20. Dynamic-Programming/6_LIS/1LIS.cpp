//Recursive
class Solution {
public:
    int solve(vector<int>a, int i, int p){
        int res=0;
        if(i==a.size())return res;
        
        res=0+solve(a,i+1,p);
        if(p==-1 || a[i]<a[p]){
            res=max(res,1+solve(a,i+1,i));
        }
        return res;
    }
    int lengthOfLIS(vector<int>& nums) {
        return solve(nums,0,-1);
    }
};


//Memoization (need right shifting of elements)
class Solution {
public:
    int solve(vector<int>a, int i, int p,vector<vector<int>>&dp){
        int res=0;
        if(i==a.size())return res;
        if(dp[i][p+1]!=-1){return dp[i][p+1];}
        res=0+solve(a,i+1,p,dp);
        if(p==-1 || a[i]>a[p]){
            res=max(res,1+solve(a,i+1,i,dp));
        }
        return dp[i][p+1]=res;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(nums,0,-1,dp);
    }
};
