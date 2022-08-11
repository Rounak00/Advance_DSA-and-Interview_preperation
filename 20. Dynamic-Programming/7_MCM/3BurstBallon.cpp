//Memoization
class Solution {
private:
    int solve(int i, int j, vector<int>& nums, vector<vector<int>>& dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int maxi = INT_MIN;
        for(int ind = i;ind<=j;ind++){
            int coins = nums[i-1]*nums[ind]*nums[j+1] + solve(i, ind-1, nums, dp) + 
                solve(ind+1, j, nums, dp);
            maxi = max(maxi, coins);
        }
        return dp[i][j] = maxi;
    }
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        
        return solve(1, n, nums, dp);
    }
};

//Tabulation
class Solution {
private:
    
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
        
        for(int i=n;i>=1;i--){
            for(int j=1;j<=n;j++){
                if(i>j){continue;}
                int maxi = INT_MIN;
                for(int ind = i;ind<=j;ind++){
                    int coins = nums[i-1]*nums[ind]*nums[j+1] + dp[i][ind-1]+ 
                        dp[ind+1][j];
                    maxi = max(maxi, coins);
                }
                dp[i][j] = maxi;
            }
        }
        return dp[1][n];
    }
};