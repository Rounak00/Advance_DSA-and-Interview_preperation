// Recursion
int solve(vector<int> weight, vector<int> value, int n, int w){
	if(w==0){return 0;} //think it logically we dont need this line
	if(n==0){
		if(weight[n]<=w){return value[n];}
		else{return 0;}
	}
	int take=INT_MIN;
	int ntake=0+solve(weight,value,n-1,w);
	if(weight[n]<=w){take=value[n]+solve(weight,value,n-1,w-weight[n]);}
	
return max(take,ntake);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	return solve(weight,value,n-1,maxWeight);
}


//Memoization
int solve(vector<int> &weight, vector<int> &value, int n, int w,vector<vector<int>>&dp){
	if(w==0){return 0;} //think it logically we dont need this line
	if(n==0){
		if(weight[n]<=w){return value[n];}
		else{return 0;}
	}
	if(dp[n][w]!=-1){return dp[n][w];}
	int take=INT_MIN;
	int ntake=0+solve(weight,value,n-1,w,dp);
	if(weight[n]<=w){take=value[n]+solve(weight,value,n-1,w-weight[n],dp);}
	
return dp[n][w]= max(take,ntake);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{   vector<vector<int>>dp(n,vector<int>(maxWeight+1,-1));
	return solve(weight,value,n-1,maxWeight,dp);
}


//Tabulation



int knapsack(vector<int> weight, vector<int> value, int n, int maxweight) 
{   vector<vector<int>>dp(n,vector<int>(maxweight+1));
	
 for(int i=weight[0]; i<=maxweight;i++){dp[0][i]=value[0];}
 
 for(int ind=1;ind<n;ind++){
	  for(int w=0;w<=maxweight;w++){
		  int take=INT_MIN;
		  int ntake=0+dp[ind-1][w];
		  if(weight[ind]<=w){
			  take=value[ind]+dp[ind-1][w-weight[ind]];
		  }
		  dp[ind][w]=max(take,ntake);
	  }
 }
	return dp[n-1][maxweight];
}