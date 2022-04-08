class Solution { //we need to add here house robber 1 logic
public:
    int robSol(vector<int>& arr) {
     int n=arr.size();
      int prev=arr[0],prev2=0;
     for(int i=1;i<n;i++){
        int pick = arr[i];
        if(i>1)
            pick += prev2;
        int nonPick = 0 + prev;
        
        int cur_i = max(pick, nonPick);
        prev2 = prev;
        prev= cur_i;
     }
      return prev;
    }
    
    int rob(vector<int>& nums) {
    int n=nums.size();
     vector<int>v1,v2;
     for(int i=0;i<n;i++){
         if(i!=0){v1.push_back(nums[i]);}
         if(i!=n-1){v2.push_back(nums[i]);}
     } 
      int ans=max(robSol(v1),robSol(v2));
    return ans;
    }
};