//LC 493

class Solution {
public:
    int ans=0;
    void merge(int low,int mid, int high,vector<int>& nums){
        vector<int> temp;
        int left=low, right=mid+1;
        int j = mid+1;
        for(int i=low;i<=mid;i++){
            while(j<=high && nums[i] > (1ll*2*nums[j])){
                j++;
            }
            ans += (j-(mid+1));
        }
        while(left<=mid && right<=high){
            if(nums[left]<=nums[right]){
                temp.push_back(nums[left]);
                left++;
            }
            else{
                temp.push_back(nums[right]);
                right++;
            }
        }
        while(left<=mid){
            temp.push_back(nums[left]);
            left++;
        }
        while(right<=high){
            temp.push_back(nums[right]);
            right++;
        }

        for(int i=low;i<=high;i++){
            nums[i]=temp[i-low];
        }
    }

    void mergeSort(int low, int high, vector<int>& nums){
        if(low>=high){
            return;
        }

        int mid=(low+high)>>1;
        mergeSort(low, mid, nums);
        mergeSort(mid+1, high, nums);
        merge(low, mid, high, nums);

    }
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        mergeSort(0, n-1, nums);
        return ans;
    }
};