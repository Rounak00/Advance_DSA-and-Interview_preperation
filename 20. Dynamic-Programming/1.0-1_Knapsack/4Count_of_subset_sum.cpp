int solve(a,n,sum){
    t[n+1][sum+1];

     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++0){
            if(i==0){t[i][j]==0;}
            if(j==0){t[i][j]==1;}
        }
    }
  for(int i=1;i<n;i++){
  for(int j=1;j<n;j++0){  
  if(a[i-1]<=j){
      t[i][j]=t[i-1][j]+t[i-1][j-a[i-1]];
  }
  else{
      t[i][j]=t[i-1][j];
  }
  }
  }
return t[n][sum];
}