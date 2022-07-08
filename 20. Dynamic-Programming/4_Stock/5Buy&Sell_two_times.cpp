//recursion:
class Solution {
public:
    int solve(vector<int>&a, int ind, int buy, int cap){
        if(cap==0)return 0;
        if(ind>=a.size())return 0;
        
        int profit;
        if(buy){
            profit=max(-a[ind]+solve(a,ind+1, 0, cap), 0+solve(a,ind+1,1,cap));
        }else{
            profit=max(a[ind]+solve(a,ind+1,1,cap-1),0+solve(a,ind+1,0,cap-1));
        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        return solve(prices, 0, 1, 2);
    }
};
//Memization:
class Solution {
public:
    int solve( vector<vector<vector<int>>>&dp,vector<int>&a, int ind, int buy, int cap){
        if(cap==0)return 0;
        if(ind>=a.size())return 0;
        if(dp[ind][buy][cap]!=-1){return dp[ind][buy][cap];}
        int profit;
        if(buy){
            profit=max(-a[ind]+solve(dp,a,ind+1, 0, cap), 0+solve(dp,a,ind+1,1,cap));
        }else{
            profit=max(a[ind]+solve(dp,a,ind+1,1,cap-1),0+solve(dp,a,ind+1,0,cap));
        }
        return dp[ind][buy][cap]= profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(dp,prices, 0, 1, 2);
    }
};

//Tabulation
class Solution {
public:
    
    
        
        int maxProfit(vector<int>& prices)
{
    // Write your code here.
    int n = prices.size();
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
    // Base Case
    // WORK WITHOUT BASE CASES
            /*no need base case bcs vactor is initially 0
        for(int i=0;i<=n;i++){
        for(int buy=0;buy<=1;buy++){
          dp[ind][buy][0]=0;
        }
        }
        
        for(buy=0;buy<=1;buy++){
        for(cap=0;cap<=2;cap++){
           dp[n][buy][cap]=0;
        }
        }
        
        */
    for(int ind=n-1;ind>=0;ind--)
    {
        for(int buy=0;buy<=1;buy++) 
        {
            for(int cap=1;cap<=2;cap++)
            {
            if(buy==1)
            dp[ind][buy][cap]= max(-prices[ind]+dp[ind+1][0][cap],dp[ind+1][1][cap]);
            else
            dp[ind][buy][cap] = max(prices[ind]+dp[ind+1][1][cap-1],dp[ind+1][0][cap]);
            }
        }
    }
    return dp[0][1][2];
}
    
};



// Space Optimization
int maxProfit(vector<int>& prices)
{
    // Write your code here.
    int n = prices.size();
    vector<vector<int>>after(2,vector<int>(3,0));
     vector<vector<int>>curr(2,vector<int>(3,0));
    // Base Case
    // WORK WITHOUT BASE CASES
    for(int ind=n-1;ind>=0;ind--)
    {
        for(int buy=0;buy<=1;buy++) 
        {
            for(int cap=1;cap<=2;cap++)
            {
            if(buy==1)
            curr[buy][cap]= max(-prices[ind]+after[0][cap],after[1][cap]);
            else
            curr[buy][cap] = max(prices[ind]+after[1][cap-1],after[0][cap]);
            }
        }
    after = curr;
    }
    return after[1][2];
}  