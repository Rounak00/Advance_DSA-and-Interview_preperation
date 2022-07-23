//

 int minimumMountainRemovals(vector<int>& a) {
        int n=a.size();
        int ans=0;
        vector<int> dp(n,1), dpr(n,1);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(a[i]>a[j] && dp[i]<dp[j]+1){
                    dp[i]=1+dp[j];
                }
            }
        }
        
         for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>i;j--){
                if(a[i]>a[j] && dpr[i]<dpr[j]+1){
                    dpr[i]=1+dpr[j];
                }
            }
        }
    for(int i=0;i<n;i++){
               ans=max(ans, (dp[i]+dpr[i])-1);
            }
            return ans;
    }

//leetcode 1671
class Solution {
public:
    int minimumMountainRemovals(vector<int>& a) {
        int n=a.size();
        int ans=0;
        vector<int> dp(n,1), dpr(n,1);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(a[i]>a[j] && dp[i]<dp[j]+1){
                    dp[i]=1+dp[j];
                }
            }
        }
        
         for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>i;j--){
                if(a[i]>a[j] && dpr[i]<dpr[j]+1){
                    dpr[i]=1+dpr[j];
                }
            }
        }
        
        for(int i=0;i<n;i++){
            if(dp[i] > 1 && dpr[i] > 1)ans=max(ans, (dp[i]+dpr[i])-1);
        }
        return n-ans;
    }
};