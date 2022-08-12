//Recursion
class Solution {
public:
    int solve(int i,vector<int>& a,int k ){
        int n=a.size();
        if(i==n){return 0;}
        int maxi=INT_MIN;
        int len=0,sum=0;
        int maxAns=INT_MIN;
        for(int j=i;j<min(n,i+k);j++){
            len++;
            maxi=max(maxi,a[j]);
            sum=(len*maxi)+solve(j+1,a,k);
            maxAns=max(maxAns,sum);
        }
        return maxAns;
    }
    int maxSumAfterPartitioning(vector<int>& a, int k) {
        int n=a.size();
        return solve(0,a,k);
        
    }
};

//Memoization

class Solution {
private:
    int solve(int ind, int n, int k, vector<int>& arr, vector<int>& dp){
        if(ind>=n) return 0;
        if(dp[ind]!=-1) return dp[ind];
        
        int maxSum = INT_MIN, maxi = INT_MIN, len=0;
        for(int i=ind;i<min(n, ind+k);i++){
            maxi = max(maxi, arr[i]);
            len++;
            int sum = len*maxi + solve(i+1, n, k, arr, dp);
            maxSum = max(sum, maxSum);
        }
        return dp[ind] = maxSum;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        
        return solve(0, n, k, arr, dp);
    }
};

//Tabulation
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
         int n = arr.size();
      
        vector<int> dp(n+1, 0);
        // dp[n] = 0; this is not required because already declared
        for(int ind = n-1; ind >= 0; ind--) {
            int len = 0;
            int sum = INT_MIN;
            int maxi = INT_MIN;
            for(int i = ind; i < min(ind+k, n); i++) {
                len++;
                maxi = max(maxi, arr[i]);
                sum = max(sum, maxi*len + dp[i+1]);
            }
            dp[ind] = sum;
        }
        return dp[0];
    }
};