class Solution {
public:
    int findMin(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;
        int n=nums.size();
        if(nums[0]<nums[n-1]||n==1)
        {
            return nums[0];
        }
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            int prev=(mid-1+n)%n;
            int next=(mid+1)%n;
            if(nums[mid]<nums[prev]&&nums[mid]<nums[next])
            {
                return nums[mid];
            }
            else if(nums[mid]<=nums[end])
            {
                end=mid-1;
            }
            else if(nums[mid]>=nums[start])
            {
                start=mid+1;
            }
        }
        return -1;

}
    
};