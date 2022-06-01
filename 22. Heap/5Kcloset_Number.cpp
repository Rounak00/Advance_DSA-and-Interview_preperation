class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        priority_queue<pair<int,int>> maxH;
        for(int i=0;i<arr.size();i++){
            maxH.push({abs(x-arr[i]) , arr[i]});
            
            if(maxH.size()>k)
                maxH.pop();
        }
        while(maxH.size()>0){
            ans.push_back(maxH.top().second);
            maxH.pop();
        }
        
        return ans;
    }
};