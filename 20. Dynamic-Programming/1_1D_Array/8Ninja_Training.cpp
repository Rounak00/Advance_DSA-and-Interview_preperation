//Recursion
int sol(vector<vactor<int>>points, int day, int last){
     if(day==0){
         int maxi=0;
        for(int i=0;i<3;i++){
            if(i!=last){
              maxi=max(maxi,points[0][i]);
            }
        }
        return maxi;
     }
     int maxi=0;
     for(int i=0;i<3;i++){
         if(i!=last){
             maxi=max(maxi, points[day][i]+sol(points,day-1,i));
         }
     }
     return maxi;
 }
 int main(){
     vector<vactor<int>>points=[[1,4,7],[7,2,8],[4,7,5]];
     int day=n.size()-1;
     return sol(points,day,3);
 }

// memoization
int sol(vector<vactor<int>>&points, int day, int last,vector<vector<int>>&dp){
    if(dp[day][last]!=-1){return dp[day][last];}
     if(day==0){
         int maxi=0;
        for(int i=0;i<3;i++){
            if(i!=last){
              maxi=max(maxi,points[0][i]);
            }
        }
        return dp[day][last]=maxi;
     }
     int maxi=0;
     for(int i=0;i<3;i++){
         if(i!=last){
             maxi=max(maxi, points[day][i]+sol(points,day-1,i));
         }
     }
     return dp[day][last]=maxi;
 }
 int main(){
     vector<vactor<int>>points=[[1,4,7],[7,2,8],[4,7,5]];
     int day=n.size()-1;
     vector<vector<int>>dp(n,vector<int>(4,-1));
     return sol(points,day,3,dp);
 }


 //tabulation

 int main(){
     vector<vactor<int>>points=[[1,4,7],[7,2,8],[4,7,5]];
     int day=n.size()-1;
     vector<vector<int>>dp(n,vector<int>(4,-1));
     dp[0][0]= max(dp[0][1],dp[0][2]);
     dp[0][1]= max(dp[0][0],dp[0][2]);
     dp[0][2]= max(dp[0][1],dp[0][0]);
     dp[0][3]= max(dp[0][1],max(dp[0][2],dp[0][0]));
     
     for(int day=1;day<n;day++){
         for(int last=0;last<4;last++){
             dp[day][last]=0;
             int maxi=0;
             for(int i=0;i<=2;i++){
                 if(i!=last){
                     maxi=points[day][i]+dp[day-1][i];
                     dp[day][last]=max(dp[day][last],maxi);
                 }
             }
         }
     }



     return dp[day-1][3];
 }


 //Space Optimization
 #include <bits/stdc++.h>

using namespace std;

int ninjaTraining(int n, vector < vector < int > > & points) {

  vector < int > prev(4, 0);

  prev[0] = max(points[0][1], points[0][2]);
  prev[1] = max(points[0][0], points[0][2]);
  prev[2] = max(points[0][0], points[0][1]);
  prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

  for (int day = 1; day < n; day++) {

    vector < int > temp(4, 0);
    for (int last = 0; last < 4; last++) {
      temp[last] = 0;
      for (int task = 0; task <= 2; task++) {
        if (task != last) {
          temp[last] = max(temp[last], points[day][task] + prev[task]);
        }
      }
    }

    prev = temp;

  }

  return prev[3];
}

int main() {

  
  vector<vector<int> > points = {{10,40,70},
                                 {20,50,80},
                                 {30,60,90}};

  int n = points.size();
  cout << ninjaTraining(n, points);
}