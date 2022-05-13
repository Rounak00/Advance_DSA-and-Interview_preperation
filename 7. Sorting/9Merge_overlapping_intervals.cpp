class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       int n = intervals.size(); 
        vector<vector<int>> mergedInterval;
        if(n == 0 || (n == 1 && intervals[0].size() == 0)) return mergedInterval;
        
        sort(intervals.begin(), intervals.end());
        
        mergedInterval.push_back(intervals[0]); //0th index pushed in case n=1  
        int index = 0;
        for(int i=1; i < n; i++) 
        {
            //overlap - begin is same. end updated
            if(intervals[i][0] <= mergedInterval[index][1]) 
                mergedInterval[index][1] = max(mergedInterval[index][1],intervals[i][1]);
            else 
            {
                mergedInterval.push_back(intervals[i]);
                index++;
            }
        }

        return mergedInterval;
    }
    
};