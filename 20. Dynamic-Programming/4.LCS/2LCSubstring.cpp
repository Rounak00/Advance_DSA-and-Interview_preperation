solve(string x, string y, inr n, int m){
    t[n+1][m+1];

    for(int i=0;i<=n;i++){
        for(int j=0;i<=m;i++){
            if(i==0||j==0){
                dp[i][j]=0;
            }
        }
    }
     for(int i=1;i<=n;i++){
         for(int j=1;j<=m;j++){
             if(x[i-1]==y[j-1]){
               return dp[n][m]=1+dp[n-1][m-1];
                }
            else{
               return dp[n][m]=0;
               }
         }
     }
}