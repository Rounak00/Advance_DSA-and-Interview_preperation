class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        
       vector<int>ans;
        int i=0;
        while(i<nums.size()){
           int correct=nums[i]-1;
            if(nums[i]!=nums[correct]){
                swap(nums[i],nums[correct]);
            }
            else{
                i++;
            }
        }
        
        for(int in=0;in<nums.size();in++){
            if(nums[in]!=in+1){
                ans.push_back(nums[in]);
            }
        }
        return ans;
    }
};
        
        
        
        
        
        
        
