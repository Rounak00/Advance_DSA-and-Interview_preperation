// map using

class Solution {
public:
vector<int> findAnagrams(string s, string p) {
unordered_map<char, int> mp;

//storing the occ. of string p in the map
for (auto &x : p){
    mp[x]++;
}
vector<int>ans;
int count = mp.size();
int k = p.size();
int i=0, j=0;

while (j < s.size()){
    //calculation part
    if (mp.find(s[j]) != mp.end()){
        mp[s[j]]--;
        if (mp[s[j]] == 0){
            count--;
        }
    }

    //window length not achived yet
    if (j-i+1 < k){
        j++;
    }

    //window length achived, find ans and slide the window
    else if (j-i+1 == k){
        //finding the ans
        if (count == 0){
            ans.push_back(i);
        }
        if (mp.find(s[i]) != mp.end()){
            mp[s[i]]++;
            if (mp[s[i]] == 1){
                count++;
            }
        }

        //slide the window
        i++;
        j++;
    }
}
return ans;
}
};