
//memoization:
solve(vector<int>&a, vector<vector<int>>&dp, int ind,int b){
 int n=a.size();
   if(ind>=n){
    return 0;
    }
    if(dp[ind][b]!=-1){return dp[ind][b];}
     int profit=0;
    if(buy){
        profit=max(-a[ind]+solve(a,dp,ind+1,0),0+solve(a,dp,ind+1,1));
    }else{
        profit=max(a[ind]+solve(a,dp,ind+2,1),0+solve(a,dp,ind+1,0));
    }
    return dp[ind][b]=profit;
}
int maxProfit(vector<int>& a) {
    int n=a.size();
    vector<vector<int>>dp(n,vector<int>(2,-1));
    solve(a,dp,0,1);
}
//tabulation:
class Solution {
public:
    int maxProfit(vector<int>& a) {
          int n=a.size();
        vector<vector<int>>dp(n+2, vector<int>(2,0));
         
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                int profit=0;
            if(buy){
            profit=max(-a[ind]+dp[ind+1][0],0+dp[ind+1][1]);
            }else{
            profit=max(a[ind]+dp[ind+2][1],0+dp[ind+1][0]);
            }
            dp[ind][buy]=profit;
            }
        }
        return dp[0][1];
    }
};