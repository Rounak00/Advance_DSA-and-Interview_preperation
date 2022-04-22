class Solution {
public:
    int minimumDifference(vector<int>& a) {
     int tot=0;
        for(int i=0;i<a.size();i++){tot+=a[i];}
        int k=tot;
        int n=a.size();
     vector<vector<bool>>dp(n, vector<bool>(k+1,0));
    for(int i=0;i<n;i++){
		dp[i][0]=true;
	}
	if(a[0]<=k){dp[0][a[0]]=true;}
	
	for(int ind=1;ind<n;ind++){
		for(int target=1;target<=k;target++){
			bool notake=dp[ind-1][target];
	        bool take=false;
	        if(a[ind]<=target){take=dp[ind-1][target-a[ind]];}
			dp[ind][target]= take || notake;
		}
	}
   int mini=1e9;
        for(int s1=0;s1<=k/2;s1++)
        {
            if(dp[n-1][s1]){
                mini=min(mini,abs((tot-s1)-s1));
            }
        }
       return mini; 
    }
};