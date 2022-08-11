
//Memoization


 int func(int i, int j, int isTrue, string& s, vector<vector<vector<long long>>>& dp)
{
    if(i > j)
    {
        return 0;
    }
    if(i == j)
    {
        if(isTrue)
        {
            return s[i] == 'T';
        }
        else
            return s[i] == 'F';
    }
    if(dp[i][j][isTrue] != -1)
    {
        return dp[i][j][isTrue];
    }
    long long ways = 0;
    for(int ind = i + 1; ind <= j - 1; ind += 2)
    {
        long long LT = func(i, ind - 1, 1, s, dp);
        long long LF = func(i, ind - 1, 0, s, dp);
        long long RT = func(ind + 1, j, 1, s, dp);
        long long RF = func(ind + 1, j, 0, s, dp);
        
        if(s[ind] == '&')
        {
            if(isTrue)
            {
                ways = (ways + (LT * RT) % mod) % mod;
            }
            else
            {          //either left or right false or both false
                ways = (ways + (LT * RF) % mod + (RT * LF) % mod + (LF * RF) % mod) % mod; 
            }
        }
        if(s[ind] == '|')
        {
            if(isTrue)
            {
                ways = (ways + (LT * RT) % mod + (LT * RF) % mod + (LF * RT) % mod) % mod;
            }
            else
            {
                ways = (ways + (LF * RF) % mod) % mod;
            }
        }
        else
        {
            if(isTrue)
            {
                ways = (ways + (LT * RF) % mod + (LF * RT) % mod) % mod;
            }
            else
            {
                ways = (ways + (LT * RT) % mod + (LF * RF) % mod) % mod;
            }
        }
    }
    return dp[i][j][isTrue] = ways;
}

int evaluateExp(string & exp) 
{
    int n = exp.size();
    vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(n, vector<long long>(2, -1)));
    return func(0, n - 1, 1, exp, dp);
}


//Tabulation



#define ll long long int
ll mod=1000000007;
int evaluateExp(string & exp) {
    int n=exp.length();
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,0)));
    for(int i=n-1;i>=0;i--)
    {
        for(int j=i;j<n;j++)
        {
            if(i==j)
            {
                dp[i][j][0]=(exp[i]=='F');
                dp[i][j][1]=(exp[i]=='T');
            }
            else 
            {
                ll ways=0;
                for(ll ind=i+1;ind<=j-1;ind+=2)
                {
                    ll lt=dp[i][ind-1][1]%mod;
                    ll rt=dp[ind+1][j][1]%mod;
                    ll lf=dp[i][ind-1][0]%mod;
                    ll rf=dp[ind+1][j][0]%mod;
                    if(exp[ind]=='&')
                    {
                        dp[i][j][0]=(dp[i][j][0]+(lt*rf+lf*rt+lf*rf))%mod;
                        dp[i][j][1]=(dp[i][j][1]+(lt*rt))%mod;
                    }
                    else if(exp[ind]=='|')
                    {
                        dp[i][j][0]=(dp[i][j][0]+(lf*rf))%mod;
                        dp[i][j][1]=(dp[i][j][1]+(lt*rf+lf*rt+lt*rt))%mod;
                    }
                    else
                    {
                        dp[i][j][0]=(dp[i][j][0]+(lt*rt+lf*rf))%mod;
                        dp[i][j][1]=(dp[i][j][1]+(lt*rf+lf*rt))%mod;
                    }
                }
            }
        }
    }
    return dp[0][n-1][1];
}