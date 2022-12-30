class Dis{
    
 public:
 vector<int>par,size;
    Dis(int n){
         // n+1 will not affect work as a immergency
        par.resize(n);
        size.resize(n);
        for(int i=0;i<n;i++){
            par[i]=i;
            size[i]=1;
        }
    }
        int find(int n){
            if (n==par[n])return n;
            else return par[n]=find(par[n]);
        }
        
        void unions(int u, int v){
            int pu=find(u);
            int pv=find(v);
            if(pu==pv)return;
            if(size[pu]>size[pv]){
                par[pv]=pu;
                size[pu]+=size[pv];
            }
            else{
                par[pu]=pv;
                size[pv]+=size[pu];
            }
        }
    
};

class Solution {
  public:
    int maxRemove(vector<vector<int>>& stone, int n) {
        int mr=0;//maxrow
        int mc=0;//maxcol
        
        for(auto it:stone){
            mr=max(mr,it[0]);
            mc=max(mc,it[1]);
            
        }
        Dis d(mr+mc+2); //Important point to remeber
        unordered_map<int,int>mp;
        
        for(auto it:stone){
            int rnode=it[0];
            int cnode=it[1]+1+mr;
            d.unions(rnode,cnode);
            mp[rnode]=1;
            mp[cnode]=1;
        }
        
        int cnt=0;
        for(auto it:mp){
            if(d.find(it.first)==it.first){
                cnt++;
            }
        }
        return (n-cnt);
    }
};