//algorithimic approach
class Solution {
public:
    bool check(string &a, string &b){
        int i=0,j=0;
        if(a.length()!=b.length()+1)return false;
        
        while(i<a.length()){
            if(j<b.length() && a[i]==b[j]){
                i++;j++;
            }else{
                i++;
            }
        }
        if(i==a.length() && j==b.length()){return true;}
        return false;
    }
    int longestStrChain(vector<string>& a) {
        int n=a.size();
        vector<int>dp(n,1);
        sort(a.begin(),a.end(),[](string& s1, string& s2){return s1.size() < s2.size();});
        int maxi=1;
        for(int i=0;i<n;i++){
            for(int p=0;p<i;p++){
               if(check(a[i],a[p]) && dp[i]<dp[p]+1){
                   dp[i]=dp[p]+1;
               } 
            }
            if(dp[i] > maxi)
            maxi = dp[i];
        }
    return maxi;
    }
    
};