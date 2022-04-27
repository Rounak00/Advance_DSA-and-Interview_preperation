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
    
    

    int main(arr, d, n){
        int tot=0; int n=arr.size();
       for(auto i:arr){tot+=i;}
       if(tot-d<0 || (tot-d)%2!=0)return false;
       vector<vector<int>>dp(n, vector<int>((total-d)/2)+1, -1);
       solve(n-1,(tot-d)/2,arr,dp)
    }
};

