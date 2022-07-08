/*only buy and sell once*/
//Bruteforce: TC:O(n^2)
int sol(vector<int>a){
int n=a.size();
int ans=0;// not intmin bcz values ar ppositive
for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
          ans=max(ans,a[j]-a[i]);
    }
}
return ans;
}
//optimize: TC:O(n)
class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n=a.size();
        int ans=0;
        int mini=a[0];
        for(int i=1;i<n;i++){
           int cost=a[i]-mini;
            ans=max(ans,cost);
            mini=min(mini,a[i]);
        }
        return ans;
    }
};