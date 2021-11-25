//Recursive:

solve(string x,string y, int n, int m){
  
    if(n==0||m==0){
         return 0;
    }

    if(x[n-1]==y[m-1]){
        return solve(x,y,n-1,m-1);
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
        return t[n][m]=solve(x,y,n-1,m-1);
    }
    else{
        return t[n][m]=max(solve(x,y,n,m-1),solve(x,y,n-1,m));
    }
}

//Tabulation:
