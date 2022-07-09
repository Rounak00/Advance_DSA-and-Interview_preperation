//(n-Longest palindromic Sussequence)


class Solution {
public:
	int solve(int i,int j,string& s,vector<vector<int>> &dp){
		if(i>j) return 0;
		if(i==j) return 1;
		
		if(dp[i][j]!=-1) return dp[i][j];
		
		if(s[i]==s[j]) return dp[i][j] = 2 + solve(i+1,j-1,s,dp);
		else return dp[i][j] = max(solve(i+1,j,s,dp),solve(i,j-1,s,dp));
	}
	int minInsertions(string s) {
		int total = s.size();
		vector<vector<int>> dp(total, vector<int>(total,-1));
		int lps = solve(0,total-1,s,dp);
		return total - lps;
	}
};