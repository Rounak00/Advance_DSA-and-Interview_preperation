//Recursive
class Solution {
public:
    int solve(vector<int>a, int i, int p){
        int res=0;
        if(i==a.size())return res;
        
        res=0+solve(a,i+1,p);
        if(p==-1 || a[i]<a[p]){
            res=max(res,1+solve(a,i+1,i));
        }
        return res;
    }
    int lengthOfLIS(vector<int>& nums) {
        return solve(nums,0,-1);
    }
};


//Memoization (need right shifting of elements)
class Solution {
public:
    int solve(vector<int>a, int i, int p,vector<vector<int>>&dp){
        int res=0;
        if(i==a.size())return res;
        if(dp[i][p+1]!=-1){return dp[i][p+1];}
        res=0+solve(a,i+1,p,dp);
        if(p==-1 || a[i]>a[p]){
            res=max(res,1+solve(a,i+1,i,dp));
        }
        return dp[i][p+1]=res;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(nums,0,-1,dp);
    }
};


//Tabulaton
class Solution {  //left shift of p only
public:
   
    int lengthOfLIS(vector<int>& a) {
        int n=a.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int ind=n-1;ind>=0;ind--){
            for(int p=ind-1;p>=-1;p--){
                
                    int res=0+dp[ind+1][p+1];
                    if(p==-1 || a[ind]>a[p]){
                        res=max(res,1+dp[ind+1][ind+1]);
                        }
                dp[ind][p+1]=res;
            }
        }
        return dp[0][0];
    }
};



//Algorithimic solution
 int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
        vector<int>dp(n,1);
        int maxi = 1;
        for(int i=0;i<n;i++)
        {
            for(int prev=0;prev<i;prev++)
            {
                if(nums[prev]<nums[i]){
                dp[i] = max(dp[i],1+dp[prev]);
                }
            }
        maxi = max(maxi,dp[i]);
        }
    return maxi;
    }


//Binary search
class Solution {
public:
   
    int lengthOfLIS(vector<int>& a) {
        int n=a.size();
        vector<int>v;
        v.push_back(a[0]);
        int len=1;
        
        for(int i=1;i<n;i++){
            if(a[i]>v.back()){
                v.push_back(a[i]);
                len++;
            }
            else{
                int ind=lower_bound(v.begin(),v.end(),a[i])-v.begin();;
                v[ind]=a[i];
            }
        }
        return len;
    }
};    


//Print LIS
/*we need algorithimic solvation here*/
 int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    int last;
        vector<int>dp(n,1), hash(n);
        int maxi = 1;
        for(int i=0;i<n;i++)
        {     hash[i]=i;
            for(int prev=0;prev<i;prev++)
            {
                if(nums[prev]<nums[i] && 1+dp[prev]>dp[i]){
                dp[i]=1+dp[prev];
                hash[i]=prev;
                }
            }
        if(maxi<dp[i]){
            maxi=dp[i];
            last=i;
        }
        }
        int lis[maxi];
        int i=1;
        lis[0]=nums[last];

        while(hash[last]!=last){
            last=hash[last];
            lis[i++]=nums[last];
        }
    return maxi;
    }