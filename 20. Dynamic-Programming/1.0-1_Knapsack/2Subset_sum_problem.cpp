bool solve(a[],s){
    int n=a.size();
     int dp[n+1][s+1];
    memset(dp,0,sizeof(dp));
           
    for(int i=0;i<=n;i++)
        for(int j=0;j<=s;j++)
        {
            if(i==0)dp[i][j]=0;
            if(j==0)dp[i][j]=1;
        }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=s;j++){
            if(nums[i-1]<=j)
                dp[i][j]=dp[i-1][j-nums[i-1]]||dp[i-1][j];
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][s];
}