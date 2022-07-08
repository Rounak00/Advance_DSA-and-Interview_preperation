//same as number 5

//memo
class Solution {
public:
    int solve( vector<vector<vector<int>>>&dp,vector<int>&a, int ind, int buy, int cap){
        
        if(ind>=a.size()|| cap<=0)return 0;
        if(dp[ind][buy][cap]!=-1){return dp[ind][buy][cap];}
        int profit;
        if(buy){
            profit=max(-a[ind]+solve(dp,a,ind+1, 0, cap), 0+solve(dp,a,ind+1,1,cap));
        }else{
            profit=max(a[ind]+solve(dp,a,ind+1,1,cap-1),0+solve(dp,a,ind+1,0,cap));
        }
        return dp[ind][buy][cap]= profit;
    }
    int maxProfit(int k,vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solve(dp,prices, 0, 1, k);
    }
};

//space opti

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
     
    vector<vector<int>>dp(2,vector<int>(k+1)),pre(2,vector<int>(k+1));
    for(int i=prices.size()-1;i>=0;i--){
        for(int j=0;j<=1;j++){
            for(int s=1;s<=k;s++){
                if(j){
                    dp[j][s]=max(-prices[i]+pre[0][s],pre[1][s]);
                    
                }
                else{
                    dp[j][s]=max(+prices[i]+pre[1][s-1],pre[0][s]);
                }
            }
            
        }
        pre=dp;
    }
   return dp[1][k];
}

};