//House Robber
//recursion
class Solution {
public:
 int f(int n, vector<int>&arr){
     if(n<0){return 0;}
     if(n==0){return arr[0];}
     
     int p= arr[n] + f(n-2,arr);
     int np=  0 + f(n-1,arr);
     return max(p,np);
 }
     
     
  int rob(vector<int>& nums) {
     int n=nums.size();
      return f(n-1,nums);
  }
};

//memoization
class Solution {
public:
 int f(int n, vector<int>&arr, vector<int>&dp){
     if(n<0){return 0;}
     if(n==0){return arr[0];}
     if(dp[n]!=-1){return dp[n];}
     int p= arr[n] + f(n-2,arr,dp);
     int np=  0 + f(n-1,arr,dp);
     return dp[n]= max(p,np);
 }
     
     
  int rob(vector<int>& nums) {
     int n=nums.size();
      vector<int>dp(n+1,-1);
     
      return f(n-1,nums,dp);
  }
};

//tabulation
class Solution {
public:     
  int rob(vector<int>& arr) {
     int n=arr.size();
      vector<int>dp(n+1,-1);
     
      dp[0]=arr[0];
      
      
     for(int i=1 ;i<n; i++){
        int pick = arr[i];
        if(i>1)
            pick += dp[i-2];
        int nonPick = 0+ dp[i-1];
        
        dp[i]= max(pick, nonPick);
    }
    
    
    return dp[n-1];
  }
};
//Space Optimazation
class Solution {
public:     
  int rob(vector<int>& arr) {
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
};