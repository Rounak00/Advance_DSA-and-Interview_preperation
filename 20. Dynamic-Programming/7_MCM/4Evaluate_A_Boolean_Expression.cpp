//Recursion


int mod=1000000007;
long long solve(int i, int j,int isTrue,string &a){
    if(i>j){return 0;}
    if(i==j){
        if(isTrue){return a[i]=='T';}
        else{return a[i]=='F';}
    }
   long long ways=0;
    for(int ind=i+1;ind<=j-1;ind+2){
       long long lt= solve(i,ind-1,1,a);
        long long rt= solve(ind+1,j,1,a);
        long long lf= solve(i,ind-1,0,a);
        long long rf= solve(ind+1,j,0,a);
        
        if(a[ind]=='&'){
            if(isTrue){ways= (ways+(lt*rt)%mod)%mod;}
            else{ways=(ways+ (lt*rf)%mod + (lf*rt)%mod + (lf*rf)%mod)%mod;}
        }
        else if(a[ind]=='|'){
            if(isTrue){ways = (ways+ (lt*rf)%mod + (lf*rt)%mod +                             (lt*rt)%mod)%mod;}
            else{ways=(ways+ (lf*rf)%mod)%mod;}
        }
        else{
            if(isTrue){ways=(ways+ (lf*rt)%mod + (lt*rf)%mod)%mod;}
            else{ways=(ways + (lt*rt)%mod + (lf*rf)%mod )%mod;}
        }
        return ways;
}
int evaluateExp(string & exp) {
    // Write your code here.
    return solve(0,exp.size()-1,1,exp)
}



//Memoization


 #include<bits/stdc++.h>

long long mod=1000000007;
long long solve(int i, int j,int isTrue,string &a, vector<vector<vector<long long>>>&dp){
    if(i>j){return 0;}
    if(i==j){
        if(isTrue){return a[i]=='T';}
        else{return a[i]=='F';}
    }
    if(dp[i][j][isTrue]!=-1){return dp[i][j][isTrue];}
   long long ways=0;
    for(int ind=i+1;ind<=j-1;ind+2){
       long long lt= solve(i,ind-1,1,a,dp);
        long long rt= solve(ind+1,j,1,a,dp);
        long long lf= solve(i,ind-1,0,a,dp);
        long long rf= solve(ind+1,j,0,a,dp);
        
        if(a[ind]=='&'){
            if(isTrue){ways= (ways+(lt*rt)%mod)%mod;}
            else{ways=(ways+ (lt*rf)%mod + (lf*rt)%mod + (lf*rf)%mod)%mod;}
        }
        else if(a[ind]=='|'){
            if(isTrue){ways = (ways+ (lt*rf)%mod + (lf*rt)%mod +                             (lt*rt)%mod)%mod;}
            else{ways=(ways+ (lf*rf)%mod)%mod;}
        }
        else{
            if(isTrue){ways=(ways+ (lf*rt)%mod + (lt*rf)%mod)%mod;}
            else{ways=(ways + (lt*rt)%mod + (lf*rf)%mod )%mod;}
        }
        return dp[i][j][isTrue]=ways;
}
int evaluateExp(string & exp) {
    // Write your code here.
    int n=exp.size();
    vector<vector<vector<long long>>>dp(n,vector<vector<long long>>(n,vector<long long>(2,-1)));
    return solve(0,n-1,1,exp,dp)
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