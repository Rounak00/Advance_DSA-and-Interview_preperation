//Recursion Code: This will give TLE.

class Solution {
public:
    vector<int> ans;
    void lds(vector<int> temp,int i,int prev,vector<int>& nums){
        
        if(i>=nums.size()){
            if(temp.size()>ans.size())  ans=temp;
            return;
        }
        if(nums[i]%prev==0){  
            temp.push_back(nums[i]);
            lds(temp,i+1,nums[i],nums);
            temp.pop_back();
        }
        lds(temp,i+1,prev,nums);
    }
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> temp;
        lds(temp,0,1,nums);
        return ans;
    }
};
// Memoziation : Accepted

class Solution {
public:
    vector<int> ans;
    vector<int> dp;
    void lds(vector<int> temp,int i,int prev,vector<int>& nums){
        if(i>=nums.size()){
            if(temp.size()>ans.size()) ans=temp;
            return;
        }
        
        if((int)temp.size()>dp[i] && (nums[i]%prev==0)){ 
            dp[i]=temp.size();
            temp.push_back(nums[i]);
            lds(temp,i+1,nums[i],nums);
            temp.pop_back();
        }
        lds(temp,i+1,prev,nums);
    }
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<=nums.size();i++) dp.push_back(-1);
        vector<int> temp;
        lds(temp,0,1,nums);
        return ans;
    }
};

//Algorithimic print approach
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& a) {
        int n=a.size();
        int maxi=INT_MIN;
        sort(a.begin(),a.end());
        vector<int> dp(n,1),hash(n);
        
        for(int i=0;i<n;i++)hash[i]=i;
        
        int hashp=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(a[i]%a[j]==0   && dp[i]<1+dp[j]){
                    dp[i]=1+dp[j];
                    hash[i]=j;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                hashp=i;
            }
        }
        
        vector<int>ans;
        ans.push_back(a[hashp]);
        while(hash[hashp]!=hashp){
            hashp=hash[hashp];
            ans.push_back(a[hashp]);
        }
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};

        
    
          
       