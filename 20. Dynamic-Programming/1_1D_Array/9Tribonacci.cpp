//Recursion
class Solution {
public:
    int tribonacci(int n) 
    {
        if (n <= 1) {
            return n;
        }    
        if (n == 2) {
            return 1;
        }
        return tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
    }
};


//Tabulation Code- (Bottom Up Dp)
class Solution {
public:
    int tribonacci(int n) {

        int arr[39];
        arr[0]=0; arr[1]=1;arr[2]=1;
        if(n<=2) return arr[n];
        for(int i=3;i<=n;i++){
            arr[i]=arr[i-1]+arr[i-2]+arr[i-3];
        }
        return arr[n];
    }
};

//Memoized Code- (Top Down Dp)
class Solution {
public:
    vector<int> dp;
    int tribonacci(int n) {
        dp.resize(n+1,-1);
        return solve(n);
        
    }
    
    int solve(int n){
        if(dp[n]!=-1) return dp[n];
        else if(n==0) return dp[0]=0; 
        else if(n==1 || n==2) return dp[n]=1;
        else return dp[n]=solve(n-1)+solve(n-2)+solve(n-3);
    }
    
};