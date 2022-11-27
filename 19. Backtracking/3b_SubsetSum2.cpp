class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        vector<int>v;
        helper(res,nums,0,v);
        return res;
    }
    
    void helper(vector<vector<int>>&res , vector<int>&nums , int start , vector<int>&v ){
            res.push_back(v);
        
        for(int i=start;i<nums.size();i++){
            if(i>start&&nums[i]==nums[i-1]) continue;
            v.push_back(nums[i]);
            helper(res,nums,i+1,v);
            v.pop_back();
        }
    }
};