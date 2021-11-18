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

 //top-down:
    
    