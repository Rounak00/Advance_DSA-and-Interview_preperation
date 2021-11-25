//Recursive:

solve(string x,string y, int n, int m){
  
    if(n==0||m==0){
         return 0;
    }

    if(x[n-1]==y[m-1]){
        return 1+solve(x,y,n-1,m-1);
    }
    else{
        return max(solve(x,y,n,m-1),solve(x,y,n-1,m));
    }
}


//Memoization:
int t[1001][1001];
memset(t,-1,sizeof(t));

solve(string x,string y, int n, int m){
  
    if(n==0||m==0){
         return 0;
    }
    if(t[n][m]!=-1){return t[m][n]}

    if(x[n-1]==y[m-1]){
        return t[n][m]=1+solve(x,y,n-1,m-1);
    }
    else{
        return t[n][m]=max(solve(x,y,n,m-1),solve(x,y,n-1,m));
    }
}

//Tabulation:

 solve(string x, string y, int n, int m){
     int dp[n+1][m+1];
    
     for(int i=0;i<=n;i++){
         for(int j=0;j<=m;j++){
             if(i==0||j==0){dp[i][j]=0;}
         }
     }

     for(int i=1;i<=n;i++){
         for(int j=1;j<=m;j++){
             if(x[i-1]==y[j-1]){
               return dp[n][m]=1+dp[n-1][m-1];
                }
            else{
               return dp[n][m]=max(dp[i-1][j],dp[i][j-1]);
               }
         }
     }


     return dp[n][m]; 
 }