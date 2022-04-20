//recursion: TC:O(3^n X 3^n) SC: O(n)
class Solution {
public:
    int solve(int i, int j1,int j2,vector<vector<int>>&a,int n, int m){
        if(j1<0||j1>m || j2<0 || j2>m){return -1e8;}
        if(i==n){
           if(j1==j2){return a[i][j1];}
        else{ return a[i][j1]+a[i][j2];}
        }
        
        
        int maxi=-1e9;
        for(int d1=-1;d1<=1;d1++){
            for(int d2=-1;d2<=1;d2++){
                if(j1==j2){maxi=max(maxi, a[i][j1]+solve(i+1,j1+d1,j2+d2,a,n,m)); }
                else{
                    maxi=max(maxi, a[i][j1]+a[i][j2]+solve(i+1,j1+d1,j2+d2,a,n,m));
                }
            }
        }
        return maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size()-1;
        int m=grid[0].size()-1;
        
        return solve(0,0,m,grid,n,m);
    }
};

//memoization: TC:O(N X M X M) X 9  SC: O(N X M X M)+ O(N)
class Solution {
public:
    int solve(int i, int j1,int j2,vector<vector<int>>&a,int n, int m,vector<vector<vector<int>>>&dp){
        if(j1<0||j1>m-1 || j2<0 || j2>m-1){return -1e8;}
        if(i==n-1){
           if(j1==j2){return dp[i][j1][j2]=a[i][j1];}
        else{ return dp[i][j1][j2]=a[i][j1]+a[i][j2];}
        }
        
        if(dp[i][j1][j2]!=-1){return dp[i][j1][j2];}
        int maxi=-1e9;
        for(int d1=-1;d1<=1;d1++){
            for(int d2=-1;d2<=1;d2++){
                if(j1==j2){maxi=max(maxi, a[i][j1]+solve(i+1,j1+d1,j2+d2,a,n,m,dp)); }
                else{
                    maxi=max(maxi, a[i][j1]+a[i][j2]+solve(i+1,j1+d1,j2+d2,a,n,m,dp));
                }
               
            }
        }
        return dp[i][j1][j2]=maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m, vector<int>(m,-1)));
        return solve(0,0,m-1,grid,n,m,dp);
    }
};

//Tabulation:  TC:O(N X M X M) X 9  SC: O(N X M X M)

class Solution {
public:
   
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
      
       vector < vector < vector < int >>> dp(n, vector < vector < int >> (m, 
  vector < int > (m, 0)));

  for (int j1 = 0; j1 < m; j1++) {
    for (int j2 = 0; j2 < m; j2++) {
      if (j1 == j2)
        dp[n - 1][j1][j2] = grid[n - 1][j1];
      else
        dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
    }
  }

  //Outer Nested Loops for travering DP Array
  for (int i = n - 2; i >= 0; i--) {
    for (int j1 = 0; j1 < m; j1++) {
      for (int j2 = 0; j2 < m; j2++) {

        int maxi = INT_MIN;

        //Inner nested loops to try out 9 options
        for (int di = -1; di <= 1; di++) {
          for (int dj = -1; dj <= 1; dj++) {

            int ans;

            if (j1 == j2)
              ans = grid[i][j1];
            else
              ans = grid[i][j1] + grid[i][j2];

            if ((j1 + di < 0 || j1 + di >= m) ||
              (j2 + dj < 0 || j2 + dj >= m))

              ans += -1e9;
            else
              ans += dp[i + 1][j1 + di][j2 + dj];

            maxi = max(ans, maxi);
          }
        }
        dp[i][j1][j2] = maxi;
      }
    }
  }

  return dp[0][0][m - 1];
    }
};
