class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        while(i<n){
            int correct=nums[i];
            if(nums[i]<n && nums[i]!=nums[correct]){
                swap(nums[correct],nums[i]);
            }else{
                i++;
            }
        }
        int j;
        for( j=0;j<n;j++){
            if(nums[j]!=j)return j;
        }
        return j;
    }
};