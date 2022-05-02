// recursion
class Solution {
public:
    int solve(vector<int>&a,int t,int n){
	if(n==0){
		if(t%a[0]==0){return t/a[0];}
		else{return 1e9;}
	}
	
	int take=1e9;
	int nottake=0+solve(a,t,n-1);
	if(a[n]<=t){take=1+solve(a,t-a[n],n);}
	return min(take,nottake);
}
    
    int coinChange(vector<int>& coins, int n) {
        int a= solve(coins,n,coins.size()-1);
        if(a==1e9){return -1;}//if ans not possible then return -1
        else{return a;}
    }
};
//memoisation
class Solution {
public:
    int solve(vector<int>&a,int t,int n, vector<vector<int>>&dp){
	if(n==0){
		if(t%a[0]==0){return t/a[0];}
		else{return 1e9;}
	}
	if(dp[n][t]!=-1){return dp[n][t];}
	int take=1e9;
	int nottake=0+solve(a,t,n-1,dp);
	if(a[n]<=t){take=1+solve(a,t-a[n],n,dp);}
	return dp[n][t]=min(take,nottake);
}
    
    int coinChange(vector<int>& coins, int n) {
        vector<vector<int>>dp(coins.size(), vector<int>(n+1,-1));
        int a= solve(coins,n,coins.size()-1,dp);
        if(a==1e9){return -1;}//if ans not possible then return -1
        else{return a;}
    }
};

//Tabulation
int minimumElements(vector<int> &num, int x)
{
     int t=x;
       int n=num.size(); 
        vector<vector<int>>dp(n, vector<int>(t+1,0));
        for(int i=0;i<=t;i++){
            if(i%num[0]==0){dp[0][i]=i/num[0];}
            else{dp[0][i]=1e9;}
        }
        
        for(int ind=1;ind<n;ind++){
            for(int tar=0;tar<=t;tar++){
                int take=1e9;
                int notake=0+dp[ind-1][tar];
               if(num[ind]<=tar){take=1+dp[ind][tar-num[ind]];}
                dp[ind][tar]=min(take,notake);
            }
        }
        
       int y= dp[n-1][t];
       if(y>=1e9){return-1;}
        return dp[n-1][t];
    }
