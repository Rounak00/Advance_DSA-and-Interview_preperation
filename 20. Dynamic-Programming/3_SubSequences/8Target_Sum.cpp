//same question as count partition Equal to subset sum

//striver approach
class Solution {
public:
   int solve(int ind, int s, vector<int>&a,vector<vector<int>>&dp){
     if(ind == 0){
        if(s==0 && a[0]==0)
            return 2;
        if(s==0 || s == a[0])
            return 1;
        return 0;
    }
        if(dp[ind][s]!=-1)return dp[ind][s];
        int pick=0;
        int notpick=solve(ind-1,s,a,dp);
        if(a[ind]<=s){pick=solve(ind-1,s-a[ind],a,dp);}
        
        return dp[ind][s]=pick+notpick;
    }
    
    int findTargetSumWays(vector<int>& nums, int d) {
        int tot=0;
        for(int i=0;i<nums.size();i++){
            tot+=nums[i];
        }
        if(tot-d<0 || (tot-d)%2!=0)return 0;
        int x=(tot-d)/2+1;
       vector<vector<int>>dp(nums.size(), vector<int>(x, -1));
       return solve(nums.size()-1,(tot-d)/2,nums,dp);
    }
};

// recursion approach
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
      int count = 0;
      int sum = 0;
      backtrack(nums, target, 0, count, sum);
      return count;
    }
  
  void backtrack(vector<int>&nums, int target, int index, int& count, int& sum) {
    if (index == nums.size()) {
      if (target == sum) count++;
    } else {
      int temp_add = sum + nums[index];
      int temp_minus = sum - nums[index];
      backtrack(nums, target, index + 1, count, temp_add);
      backtrack(nums, target, index + 1, count, temp_minus);
    }
  }
};