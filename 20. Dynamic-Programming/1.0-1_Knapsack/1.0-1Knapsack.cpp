 //Recursive:

 int knapsack(int wt[],int val[], int w,int n){
     if(w==0||n==0){
         return 0;
     }

     if(wt[n-1]<=w){
         return max(
          (val[n-1]+knapsack(wt,val,w-wt[n-1],n-1)),
          (knapsack(wt,val,w,n-1))
         );
     }
     else if(wt[n-1]>w){return knapsack(wt,val,w,n-1); }
 }

 // memoization:
   
int t[1002][1002];
memset(t,-1,sizeof(t));

   int knapsack(int wt[],int val[], int w,int n){
     if(w==0||n==0){
         return 0;
     }

      if(t[n][w]==-1){return t[n][w];}

     if(wt[n-1]<=w){
         return t[n][w]max(
          (val[n-1]+knapsack(wt,val,w-wt[n-1],n-1)),
          (knapsack(wt,val,w,n-1))
         );
     }
     else if(wt[n-1]>w){return t[n][w]= knapsack(wt,val,w,n-1); }
 }

 //tabulation:
    int t[n+1][w+1];
    for(int i=0;i<1;i++){
        for(int j=0;j<1;j++){
            t[i][j]==0;
        }
    }
    for(int i=1;i<n+1;i++){ 
        for(int j=1;j<n+1;j++){  
          if(wt[i-1]<=j)
           {
            t[i][j]= max(
            (val[i-1]+t[i-1][j-wt[i-1]]),
            t[i-1][w];
             );
         }
          else t[i][j]=t[i-1][j];
        }
    }
    return t[n][w];
 

 //for dp TC: O(NW)