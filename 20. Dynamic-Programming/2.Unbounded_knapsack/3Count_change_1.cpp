 //Maximum number of ways
 
  int t[n+1][w+1];
    for(int i=0;i<1;i++){
        for(int j=0;j<1;j++){
            if(i==0){t[i][j]=0;}
            if(j==0){t[i][j]=1;}
        }
    }
    for(int i=1;i<n+1;i++){ 
        for(int j=1;j<n+1;j++){  
          if(wt[i-1]<=j)
           {
            t[i][j]= 
            (t[i][j-wt[i-1]]),
            t[i-1][j];
             ;
         }
          else t[i][j]=t[i-1][j];
        }
    }
    return t[n][w];

    //here wt is coin array