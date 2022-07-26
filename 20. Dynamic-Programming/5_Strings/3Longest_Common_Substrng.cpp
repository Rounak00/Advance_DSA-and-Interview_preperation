//Recursion
int LCS(string str1, string str2, int n, int m, int count)
{
    if (n==0 || m==0)
        return count;
    if (str1[n-1] == str2[m-1])
        return LCS(str1, str2, n-1, m-1, count+1);
    return max(count, max(LCS(str1, str2, n-1, m, 0), LCS(str1, str2, n, m-1, 0)));
}

//memoization

//tabulation
void lcs(string s1, string s2) {

  int n = s1.size();
  int m = s2.size();

  vector < vector < int >> dp(n + 1, vector < int > (m + 1, 0));
  for (int i = 0; i <= n; i++) {
    dp[i][0] = 0;
  }
  for (int i = 0; i <= m; i++) {
    dp[0][i] = 0;
  }
  int ans=0;
  for (int ind1 = 1; ind1 <= n; ind1++) {
    for (int ind2 = 1; ind2 <= m; ind2++) {
      if (s1[ind1 - 1] == s2[ind2 - 1])
        dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
        ans=max(ans,dp[ind1][ind2]);
      else
        dp[ind1][ind2] = 0 ;
    }
  }
  return ans;
}