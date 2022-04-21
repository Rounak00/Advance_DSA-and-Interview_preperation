//recursion
class Solution {
public:
    bool check(int in, int target, vector<int>nums){
        if(target==0){return true;}
        if(in==0){return nums[0]==target;}
        
        bool take=false;
        bool notake=check(in-1, target,nums);
        if(nums[in]<=target){take=check(in-1,target-nums[in],nums);}
        return take|notake;
    }
    bool canPartition(vector<int>& nums) {
        int tot=0;
        for(int i=0;i<nums.size();i++){
            tot+=nums[i];
        }
        if(tot%2!=0){return false;}
        return check(nums.size()-1,tot/2,nums);
    }
};
//memoization
class Solution {
public:
    bool check(int in, int target, vector<int>&nums,vector<vector<int>>&dp){
        if(target==0){return true;}
        if(in==0){return nums[0]==target;}
        if(dp[in][target]!=-1){return dp[in][target];}
        bool take=false;
        bool notake=check(in-1, target,nums,dp);
        if(nums[in]<=target){take=check(in-1,target-nums[in],nums,dp);}
        return dp[in][target]=take||notake;
    }
    bool canPartition(vector<int>& nums) {
        int tot=0;
        for(int i=0;i<nums.size();i++){
            tot+=nums[i];
        }
        if(tot%2!=0){return false;}
        vector<vector<int>>dp(nums.size(),vector<int>(tot/2+1,-1));
        return check(nums.size()-1,tot/2,nums, dp);
    }
};

//Tabulation have same approach as previous question (Subset sum equal to target)
