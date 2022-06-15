//same as number 5
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