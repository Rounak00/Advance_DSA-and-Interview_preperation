//buy ans sell multiple stocks but each time only holds one stock
//recursion:
int solve(vector<int>&a, int ind, int buy){
    if(ind==n){return 0;}
    int pro=0;
    if(buy){
       pro=max(-a[ind]+solve(a,ind+1,0),0+solve(a,ind+1,1));
    }else{
        pro= max(a[ind]+solve(a,ind+1,1),0+solve(a,ind+1,0));
    }
}
int sol(vector<int>a){
   
    int ans=solve(a,0,1);
    return ans;
}
//memoization:
class Solution {
public:
    int solve(vector<int>&a, vector<vector<int>>&dp,int ind, int buy){
        if(ind==a.size()){return 0;}
        if(dp[ind][buy]!=-1){return dp[ind][buy];}
        int profit=0;
        if(buy){
            profit=max(-a[ind]+solve(a,dp,ind+1,0),0+solve(a,dp,ind+1,1));
        }else{
            profit=max(a[ind]+solve(a,dp,ind+1,1),0+solve(a,dp,ind+1,0));
        }
        return dp[ind][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n, vector<int>(2,-1));
        return solve(prices,dp, 0,1);
    }
};
//Tabulation:
int maxProfit(vector<int>& a) {
        int n=a.size();
        vector<vector<int>>dp(n+1, vector<int>(2,0));
         dp[n][0]=dp[n][1]=0;
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                int profit=0;
            if(buy){
            profit=max(-a[ind]+dp[ind+1][0],0+dp[ind+1][1]);
            }else{
            profit=max(a[ind]+dp[ind+1][1],0+dp[ind+1][0]);
            }
            dp[ind][buy]=profit;
            }
        }
        return dp[0][1];
    }

//striver space optimization:
class Solution {
public:
    int maxProfit(vector<int>& a) {
        int aheadbuy, aheadnotbuy, currentbuy, currentnotbuy;
        aheadbuy=aheadnotbuy=0;
        for(int i=a.size()-1;i>=0;i--){
            currentnotbuy=max(a[i]+aheadbuy, 0+aheadnotbuy);
            currentbuy=max(-a[i]+aheadnotbuy,0+aheadbuy);
            aheadbuy=currentbuy;
            aheadnotbuy=currentnotbuy;
        }
        return aheadbuy;
    }};

    
//SpaceOptimized:
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        for(int i=1;i<(prices.size());i++){
            if(prices[i]>prices[i-1]){
                profit=profit+(prices[i]-prices[i-1]);
            }
        }
        return profit;
    }
};