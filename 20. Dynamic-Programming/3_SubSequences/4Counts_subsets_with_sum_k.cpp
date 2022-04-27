//recursion:
  int solve(int ind, int s, vector<int>&a){
        if(s==0){return 1;}
        if(ind==0){return (a[ind]==s);}
        
        int pick=0;
        int notpick=solve(ind-1,s,a);
        if(a[ind]<=s){pick=solve(ind-1,s-a[ind],a);}
        
        return pick+notpick;
    }
int findWays(vector<int> &num, int tar)
{
        int n=num.size();
        return solve(n-1,tar,num);
}
    

//memoization
class Solution {
public:
    int solve(int ind, int s, vector<int>&a,vector<vector<int>>&dp){
        if(s==0){return 1;}
        if(ind==0){return (a[ind]==s);}
        if(dp[ind][s]!=-1)return dp[ind][s];
        int pick=0;
        int notpick=solve(ind-1,s,a,dp);
        if(a[ind]<=s){pick=solve(ind-1,s-a[ind],a,dp);}
        
        return dp[ind][s]=pick+notpick;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>ans(n,vector<int>(target+1,-1));
        return solve(n-1,target,nums,ans);
    }
};
//tabulation
class Solution {
public:
    int solve(int ind, int s, vector<int>&a,vector<vector<int>>&dp){
        if(s==0){return 1;}
        if(ind==0){return (a[ind]==s);}
        if(dp[ind][s]!=-1)return dp[ind][s];
        int pick=0;
        int notpick=solve(ind-1,s,a,dp);
        if(a[ind]<=s){pick=solve(ind-1,s-a[ind],a,dp);}
        
        return dp[ind][s]=pick+notpick;
    }
    
    int findTargetSumWays(vector<int>& a, int target) {
        int n=a.size();
        vector<vector<int>>dp(n,vector<int>(target+1,0));
       
        for(int i=0;i<=n-1;i++){
            dp[i][0]=1;
        }
        if(a[0]<=target){dp[0][a[0]]=1;}
        
        for(int i=1;i<n;i++){
            for(int j=0;j<=target;j++){
                int pick=0;
                int notpick=dp[i-1][j];
                if(a[i]<=j){pick=dp[i-1][j-a[i]];}
            }
        }
        return dp[n-1][target];
    }
};
   