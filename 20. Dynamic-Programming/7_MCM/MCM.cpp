//Recursion

int solve(vector<int>a, int n,int i, int j){
if(i==j)return 0;
  int mini=INT_MAX;
  int step=0;
  
  for(int k=i;k<j;k++){
    step=(a[i-1]*a[k]*a[j])+solve(a,n,i,k)+solve(a,n,k+1,j);
    mini=min(mini,step);
  }
  return mini;
}

int mcm(inr n,vector<int>a){
  solve(a,n,1,n-1);
}

//Memoization
int solve(vector<int>a, int n,int i, int j,vector<vector<int>>dp){
if(i==j)return 0;
  int mini=INT_MAX;
  int step=0;
  if(dp[i][j]!=-1){return dp[i][j];}
  for(int k=i;k<j;k++){
    step=(a[i-1]*a[k]*a[j])+solve(a,n,i,k,dp)+solve(a,n,k+1,j,dp);
    mini=min(mini,step);
  }
  return dp[i][j]= mini;
}

int mcm(inr n,vector<int>a){
  vector<vector<int>>dp(n,vector<int>(n,-1));
  solve(a,n,1,n-1,dp);
}
