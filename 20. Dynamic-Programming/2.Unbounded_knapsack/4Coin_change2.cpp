class Solution {
public:
    int coinChange(vector<int>& coin, int amount) {
        int n=coin.size();
        int infy=INT_MAX-1;
    
       int dp[n+1][amount+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=amount;j++){
                if(i==0){dp[i][j]=infy;}
                if(j==0){dp[i][j]=0;}
                if(i==1){
                    if(j%coin[i-1]==0){
                        dp[i][j]=j/coin[i-1];
                    }
                    else{
                        dp[i][j]=infy;
                    }
                }               
            }
        }
        
        
        for(int i=2;i<=n;i++){ //here we can  do it with 1 and 2 your choice bcz we already intialize one
            for(int j=1;j<=amount;j++){
                if(coin[i-1]<=j){
                    dp[i][j]=min(dp[i-1][j],dp[i][j-coin[i-1]]+1);
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][amount]==INT_MAX-1?-1:dp[n][amount];
    }
};