//recursion
class Solution {
public:
    int rec(vector<int> &cost, int n){
       if(n<0){return 0;}
       else if(n==0 || n==1){
           return cost[n]
       } 
        
       return cost[n]+ min(rec(cost,n-1),rec(cost,n-2));
        
    }
    int minCostClimbingStairs(vector<int>& cost) {
         int dest=cost.size();
        
         return min(rec(cost, dest-1),rec(cost,dest-2);
        
    }
};
//memoization:
// Top Down Memoization - O(n) 1ms

public int minCostClimbingStairs(int[] cost) {
	int n = cost.length;
	vector<int>dp(n,0);
	return min(minCost(cost, n-1,dp), minCost(cost, n-2,dp));
}
private int minCost(int cost[], int n, vector<int>dp) {
	if (n < 0) return 0;
	if (n==0 || n==1) return cost[n];
	if (dp[n] != 0) return dp[n];
	dp[n] = cost[n] + min(minCost(cost, n-1), minCost(cost, n-2));
	return dp[n];
}
//tabulation:
public int minCostClimbingStairs(int cost[]) {
	int n = cost.length;
	int dp[n];
    dp[0]=cost[0];
    dp[1]=cost[1];
	for (int i=2; i<n; i++) {
		
		 dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
	}
	return min(dp[n-1], dp[n-2]);
}

//Space Optimized:
int minCostClimbingStairs(int cost[]) {
	int n = cost.length;
	int first = cost[0];
	int second = cost[1];
	if (n<=2) return min(first, second);
	for (int i=2; i<n; i++) {
		int curr = cost[i] + min(first, second);
		first = second;
		second = curr;
	}
	return min(first, second);
}