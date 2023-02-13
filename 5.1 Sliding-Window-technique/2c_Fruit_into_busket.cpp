class Solution {
public:
    int totalFruit(vector<int>& s) {
        unordered_map<int,int> mp;
        int j=0;
        int i=0;
        int ans=0;
        int count=0;
        while(j<s.size())
        {
            mp[s[j]]++;
            if(mp[s[j]]==1)
            {
                count++;
            }
            if(count==2)
            {
                ans=max(ans,j-i+1);
            }
            else if(count<2)
            {
                ans=j-i+1;
            }
            else
            {
                while(count>2 && i<=j)
                {
                    mp[s[i]]--;
                    if(mp[s[i]]==0)
                    {
                        count--;
                    }
                    i++;
                    if(count==2){
                        ans=max(ans,j-i+1);
                    }
                }
            }
            j++;
        }
        return ans;
    }
};