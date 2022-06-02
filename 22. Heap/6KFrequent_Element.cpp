class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(int num : nums){
            map[num]++;
        }
        
        vector<int> res;
        // pair<first, second>: first is frequency,  second is number
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; 
        for(auto it = map.begin(); it != map.end(); it++){
            pq.push(make_pair(it->second, it->first));
            if(pq.size() > k){
                pq.pop();
            }
        }
        while(pq.size()>0){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};


//Frequent words leetcode version
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> hashmap;
        for(string& word : words) {
            hashmap[word] += 1;
        }
        priority_queue<pair<int, string>, vector<pair<int, string>>, MyComp> pq;
        for(auto it = hashmap.begin(); it != hashmap.end(); ++it) {
            pq.push(make_pair(it->second, it->first));
            if(pq.size() > k) pq.pop();
        }
        vector<string> res;
        while(!pq.empty()) {
            res.insert(res.begin(), pq.top().second);
            pq.pop();
        }
        return res;
    }
private:
    struct MyComp {
        bool operator() (const pair<int, string>& a, const pair<int, string>& b) {
            if(a.first != b.first) {
                return a.first > b.first;
            }
            else {
                return a.second < b.second;
            }
        }
    };
};