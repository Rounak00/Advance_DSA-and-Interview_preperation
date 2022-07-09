// memoization
class Solution {
public:
    int dp[1001][1001];
    int solve(string s,string r,int m,int n){
        if(m==0 || n==0) return 0;
        if(dp[m][n] != -1) return dp[m][n];
        if(s[m-1]==r[n-1]) return dp[m][n] = 1 + solve(s,r,m-1,n-1);
        else return dp[m][n] = max(solve(s,r,m-1,n),solve(s,r,m,n-1));
        
    }
    
    int longestPalindromeSubseq(string s) {
        int n =s.length();
        if(n==1) return 1;
        string r = s;
        reverse(r.begin(),r.end());
        memset(dp,-1,sizeof(dp));
        return solve(s,r,n,n);
    }
};