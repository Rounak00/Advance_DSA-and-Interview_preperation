bool solve(a[],sum){
    int n=a.size();
    int t[n+1][sum+1];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++0){
            if(i==0){t[i][j]==false;}
            if(j==0){t[i][j]==true;}
        }
    }
   for(int i=1;i<n;i++){
        for(int j=1;j<n;j++0){
       if(t[i-1]<=sum){
           t[i][j]=(t[i-1][j-a[i-1]]||t[i-1][j]);
       }
       else{
           t[i][j]=t[i-1][j];
       }
        }
   } 
   return t[n][sum];  
}