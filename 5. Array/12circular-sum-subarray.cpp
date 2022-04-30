class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int n = A.size();
        int max_straight_SUM = INT_MIN;
        int min_straight_SUM = INT_MAX;
        int array_SUM = 0;
        
        int temp_maxSUM = 0;
        int temp_minSUM = 0;
        
        for(int i=0;i<n;++i)
        {
            array_SUM +=A[i];
            
            temp_maxSUM += A[i];
			if(temp_maxSUM > max_straight_SUM){max_straight_SUM=temp_maxSUM;}
            if(temp_maxSUM<0){temp_maxSUM=0;}
            
            
            temp_minSUM += A[i];
            if(temp_minSUM<min_straight_SUM){min_straight_SUM=temp_minSUM;}
            if(temp_minSUM>0){temp_minSUM=0;}
        }
        if(array_SUM==min_straight_SUM)
            return max_straight_SUM;
        return max(max_straight_SUM,(array_SUM-min_straight_SUM));
    }
};

