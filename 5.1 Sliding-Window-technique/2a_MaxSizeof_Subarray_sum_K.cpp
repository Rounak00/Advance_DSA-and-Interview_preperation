//sliding window possible if elements are positive 
class Solution {
public:
 int subarraySum(vector<int>& nums, int k) {
   int ans=INT_MIN;
   int sum=0;
     int i=0;
     int j=0;
     while(j<nums.size()){ 
         sum+=nums[j];
         if(sum<k){j++;}
         else if(sum==k){ans=max(ans,j-i+1);j++;}
          
         else if(sum>k){
             while(sum>k){
                 sum-=nums[i];
                 i++;
             }
             j++;
         }
     }
 return ans;
 }
};
//prefix sum if elemetns are not positive

int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int sum=0,ans=0;
        mp[sum] = 1;
        for(auto it:nums){
            sum += it;
            int find = sum - k;
            if(mp.find(find) != mp.end()){
                ans += mp[find];
            }
            mp[sum]++;
        }
        return ans;

    }