
class Dis{
    vector<int>par,size;
 public:
    Dis(int n){
        n=n+1; // n+1 will not affect work as a immergency
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
    int makeConnected(int n, vector<vector<int>>& edge) {
        
     Dis d(n);
        int ex=0;
        for(auto it:edge){
            int u=it[0];
            int v=it[1];
            
            if(d.find(u)!=d.find(v)){d.unions(u,v);}
            else{ex++;}
        }
        int comp=0;
        for(int i=0;i<n;i++){
            if(d.find(i)==i){comp++;}
        }
        comp=comp-1;
        
        if(ex>=comp){return comp;}
       
        return -1;
    }
};