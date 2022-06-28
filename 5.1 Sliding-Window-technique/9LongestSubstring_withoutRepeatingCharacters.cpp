class Solution {
public:
   int lengthOfLongestSubstring(string str) {
        int i, j, res = INT_MIN;
    map<char, int> mp;
     i =j = 0;
    int n=str.size();
    if(n==0){return 0;}   
    while(j < n)
    {
        mp[str[j]]++;
        
         if(mp.size() == j-i+1){  res = max(res, j-i+1); j++;}
           
        else if(mp.size() <j-i+1)
        {
            while(mp.size() <j-i+1)
            {
                mp[str[i]]--;
                if(mp[str[i]] == 0)
                    mp.erase(str[i]);
                ++i;
                if(mp.size() == j-i+1)
                    res = max(res, j-i+1);
            }
            ++j;
        }
        
    }
    
    return res;
    }
};