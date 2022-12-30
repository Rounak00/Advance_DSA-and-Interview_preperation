class Dis{
    vector<int>par,size;
 public:   Dis(int n){
        n=n+1;
        par.resize(n);
        size.resize(n);
        for(int i=0;i<n;i++){
            par[i]=i;
            size[i]=1;
        }
    }
    
    int find(int n){
        if(par[n]==n)return n;
        else { return par[n]=find(par[n]);}
    }
    void unions(int u, int v){
        int pu=find(u);
        int pv=find(v);
        if(pu==pv)return;
        if(size[pu]>size[pv]){par[pv]=pu; size[pu]+=size[pv];}
        else{ par[pu]=pv; size[pv]+=size[pu]; }
    }
    
};


class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& acc) {
         int n=acc.size();
        Dis d(n);
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++){
            for(int j=1;j<acc[i].size();j++){
                string mail=acc[i][j];
                if(mp.find(mail)==mp.end()){
                    mp[mail]=i;
                }
                else{
                    d.unions(i,mp[mail]);
                }
            }
        }
        
        vector<string>merge[n];
        for(auto it:mp){
            int node=d.find(it.second);
            string mail=it.first;
            
            merge[node].push_back(mail);
        }
        
        vector<vector<string>>ans;
        
        for(int i=0;i<n;i++){
            if(merge[i].size()==0)continue;
            else{
                sort(merge[i].begin(),merge[i].end());
                vector<string>t;
                t.push_back(acc[i][0]);
                for(auto it:merge[i]){
                    t.push_back(it);
                }
                ans.push_back(t);
            }
        }
        return ans;
    }
};


// Time Complexity : O(m*n*logn))+O(4 * Alpha)
// Space Complexity : O(M*N)