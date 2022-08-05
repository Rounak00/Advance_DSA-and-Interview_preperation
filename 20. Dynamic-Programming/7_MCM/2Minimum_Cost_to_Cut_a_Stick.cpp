//Memoization
class Solution {
public:
    int solve(int i, int j, vector<int>&c,vector<vector<int>>&dp){
        int mini=INT_MAX;
        if(i>j){return 0;}
        if(dp[i][j]!=-1){return dp[i][j];}
        for(int ind=i;ind<=j;ind++){
            int cost= c[j+1]-c[i-1]+solve(i,ind-1,c,dp)+solve(ind+1,j,c,dp);
            mini=min(mini,cost);
        }
        return dp[i][j]= mini;
    }
    int minCost(int n, vector<int>& cuts) {
        
        int c=cuts.size();
        vector<vector<int>>dp(c+1,vector<int>(c+1,-1)) 
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        return solve(1,c,cuts,dp);
    }
};


//Tabulation
class Solution {
public:
    
    int minCost(int n, vector<int>& cuts) {
        
        int c=cuts.size();
        vector<vector<int>>dp(c+2,vector<int>(c+2,0)) ;
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        
        for(int i=c;i>=1;i--){
            for(int j=1;j<=c;j++){
                       
                        if(i>j){continue;}
                        int mini=INT_MAX;
                        
                        for(int ind=i;ind<=j;ind++){
                            int cost= cuts[j+1]-cuts[i-1]+dp[i][ind-1]+dp[ind+1][j];
                            mini=min(mini,cost);
                        }
                         dp[i][j]= mini;
            }
        }
        
        return dp[1][c];
    }
};
