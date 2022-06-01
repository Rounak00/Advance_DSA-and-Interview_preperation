class Solution {
public:
    vector<int> frequencySort(vector<int>&a) {
        unordered_map<int, int>mp;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>h;
        
        int n=a.size();
        for(int i=0;i<n;i++){
            mp[a[i]]++;
        }
        for(auto &it:mp){
            h.push({it.second,it.first});
        }
        vector<int>ans;
        while (h.size() > 0) {
			int f = (int)h.top().first;
			int v = (int)h.top().second;
			for (int i = 1; i <= f; i++) {
				ans.push_back(v);
			}
        }
        return ans;
        
    }
};
//Leetcode version
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto it : mp){
            pq.push({-it.second,it.first});
        }
        vector<int> result;
        while(!pq.empty()){
            int x = pq.top().first;
            for(int i=0;i<abs(x);i++){
                result.push_back(pq.top().second);
            }
            pq.pop();
        }
        return result;
    }
};
