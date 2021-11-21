class Solution {
public:
    int CountSubsetsWithSum(vector<int>& nums,int sum) {
       int n= nums.size();
	int t[n + 1][sum + 1]; // DP - matrix
	// initialization
	t[0][0] = 1;
	int k = 1;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= sum; j++) {
			if (i == 0 && j > 0)
				t[i][j] = 0;
			if (j == 0 && i > 0) {
				if (nums[i - 1] == 0) {
					t[i][j] = pow(2, k);
					k++;
				}
				else
					t[i][j] = t[i - 1][j];
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sum; j++) {
			if (nums[i - 1] <= j)
				t[i][j] = t[i - 1][j - nums[i - 1]] + t[i - 1][j];
			else
				t[i][j] = t[i - 1][j];
		}
	}

	return t[n][sum];
}
    
    
    int findTargetSumWays(vector<int>& nums, int diff) {
        int n= nums.size();
        diff=abs(diff);
	    int sumOfArray = 0;
	for (int i = 0; i < n; i++)
		sumOfArray += nums[i];

	if ((sumOfArray + diff) % 2 != 0)
		return 0;
	else
		return CountSubsetsWithSum(nums, (sumOfArray + diff) / 2);

    }
};

/*
memoization solution:
 vector<vector<int>> dp;
    int sum;
    
    int fun(int total,vector<int> v,int tar,int i)
    {
        if(i<0)
        {
            if(total-(sum-total)==tar)
                return 1;
            
            return 0;
        }
        
        if(dp[i][total]!=-1)
            return dp[i][total];
        
        if(total-v[i]>=0)
        return dp[i][total] = fun(total-v[i],v,tar,i-1) + fun(total,v,tar,i-1);
        
        else
            return dp[i][total] = fun(total,v,tar,i-1);
    }
    
    int findTargetSumWays(vector<int>& v, int tar) 
    {
        int total = 0;
        int n = v.size();
        
        for(int i=0;i<v.size();i++)
            total+=v[i];
        
        sum = total;
        
        dp.clear();
        dp.resize(n+1,vector<int> (total+1,-1));
        
        return fun(total,v,tar,n-1);
    }
};
*/