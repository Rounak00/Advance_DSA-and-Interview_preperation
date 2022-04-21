//Recursion:
bool check(int n, int k, vector<int>a){
	if(k==0){return true;}
	if(n==0){return a[0]==k;}
	bool notake=check(n-1, k, a);
	bool take=false;
	if(a[n]<=k){take=check(n-1, k-a[n],a);}
	
	return take | notake;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    return check(n-1,k,arr);
}
//memoization: O(m X n) SC: O(n)+O(n X m)
bool check(int n, int k, vector<int>&a,vector<vector<int>>&dp){
	if(k==0){return true;}
	if(n==0){return a[0]==k;}
	if(dp[n][k]!=-1){return dp[n][k];}
	bool notake=check(n-1, k, a,dp);
	bool take=false;
	if(a[n]<=k){take=check(n-1, k-a[n],a,dp);}
	
	return dp[n][k]=take || notake;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
	vector<vector<int>>dp(n, vector<int>(k+1,-1));
    return check(n-1,k,arr,dp);
}
//here we take k+1 not n bcz n is index and we use only 0 to n-1 index other hand k use o to k index thats why


//Tabulation: no stack sape and similar to memo

bool subsetSumToK(int n, int k, vector<int> &a) {
	vector<vector<bool>>dp(n, vector<bool>(k+1,0));
    for(int i=0;i<n;i++){
		dp[i][0]=true;
	}
	if(a[0]<=k){dp[0][a[0]]=true;}
	
	for(int ind=1;ind<n;ind++){
		for(int target=1;target<=k;target++){
			bool notake=dp[ind-1][target];
	        bool take=false;
	        if(a[ind]<=target){take=dp[ind-1][target-a[ind]];}
			dp[ind][target]= take || notake;
		}
	}
	return dp[n-1][k];
}