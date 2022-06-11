class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& num1, vector<int>& num2, int k) {
        int n=num1.size();
        int m=num2.size();
        
        vector<vector<int>>res;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        
        for(int i=0;i<n && i<k;i++){pq.push({num1[i]+num2[0],num1[i],0});}
        
        while(k-- && pq.empty()==false){
            auto t=pq.top();
            pq.pop();
            
            res.push_back({t[1],num2[t[2]]});
            if(t[2]==m-1)continue;
            
            pq.push({t[1]+num2[t[2]+1],t[1],t[2]+1});
        }
        return res;
    }
};