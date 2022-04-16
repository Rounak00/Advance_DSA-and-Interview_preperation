//Recursion
 int climbStairs(int n) {
     if(n==1){return 1;}
     if(n==2){return 2;}
        return climbStairs(n-1)+climbStairs(n-2);
    }
//memoization
int t[46]={0};
class Solution {
public:
    int climbStairs(int n) {
        if(n==1) {t[n]=1; return 1;}
        if(n==2) {t[n]=2; return 2;}
        else if(t[n]!=0) return t[n];
        t[n] = climbStairs(n-1)+climbStairs(n-2);
        return t[n];
    }
};
//tabulation
 int climbStairs(int n) {
        int t[n+1];
        for(int i=0;i<=n;i++) t[i]=0;
        t[1]=1;
        if(n>=2) t[2]=2;
        for(int i=3;i<=n;i++){
             t[i] = t[i-1]+t[i-2];    
        }
        return t[n];
    }
//space optimazation
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        int prev = 2, prev2 = 1, res;
        for (int i = 3; i <= n; i++) {
            res = prev + prev2;
            prev2 = prev;
            prev = res;
        }
        return res;
    }
};

//if question gives you your present stair and need to go nth stair then 
 int countDistinctWayToClimbStairHelper(long long currStep, long long nStairs)
{
 if (currStep > nStairs)
    {
        return 0;
    }

    //  We reached our destination return that we got one way to reach nStairs
    if (currStep == nStairs)
    {
        return 1;
    }

   
    int oneStepcount = countDistinctWayToClimbStairHelper(currStep + 1, nStairs);


    int twoStepCount = countDistinctWayToClimbStairHelper(currStep + 2, nStairs);

    return (oneStepcount + twoStepCount);
}
// here we call two functions simultanously bcz decrese stack space


//Tabulation
#include <bits/stdc++.h>

using namespace std;


int main() {

  int n=3;
  vector<int> dp(n+1,-1);
  
  dp[0]= 1;
  dp[1]= 1;
  
  for(int i=2; i<=n; i++){
      dp[i] = dp[i-1]+ dp[i-2];
  }
  cout<<dp[n];
  return 0;
}

//Space Optimized
#include <bits/stdc++.h>

using namespace std;


int main() {

  int n=3;
  
  int prev2 = 1;
  int prev = 1;
  
  for(int i=2; i<=n; i++){
      int cur_i = prev2+ prev;
      prev2 = prev;
      prev= cur_i;
  }
  cout<<prev;
  return 0;
}
