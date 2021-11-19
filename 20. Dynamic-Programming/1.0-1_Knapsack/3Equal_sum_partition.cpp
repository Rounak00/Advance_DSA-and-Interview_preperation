  bool sub(int a[],int sum){ 
  int n=a.size();
for(int i=0;i<n;i++){
    sum=sum+a[i];
}
if(sum%2!=0){return false; }
else if(sum%2==0){
   return solve(a,sum,n);
}}

bool solve(sum,a,n){
     int t[n+1][sum+1];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++0){
            if(i==0){t[i][j]==false;}
            if(j==0){t[i][j]==true;}
        }
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++0){
             if(a[i-1]<=j){
                 t[i][j]=(t[i-1][j-a[-1]]||t[i-1][j]);
             }
             else{
                 t[i][j]=t[i-1][j];
             }
        }
    }
    return t[n][sum];
}

   
   




          