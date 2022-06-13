class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    	int n = nums.size(), l,int i;
      for(i=n-2;i>=0;i--){
          if(nums[i]<nums[i+1]){
              break;
          }
      }
      if(i<0) reverse(nums.begin(), nums.end());
      else {
            for(l=n-1;l>=0;l++){
                if(num[l]>num[i]){
                    break;
                }
            }
            swap(nums[l],nums[k]);
            reverse(nums.begin()+k+1,nums.end());
    }
}
};
