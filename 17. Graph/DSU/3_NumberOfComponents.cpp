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
            if(pu==pv){return;}
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
    int numProvinces(vector<vector<int>> adj, int V) {
        Dis d(V);
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j]==1){
                    d.unions(i,j);
                }
            }
        }
        int cnt=0;
        for(int i=0;i<V;i++){ // we can do this i=1 and i<=v;
            if(d.find(i)==i){cnt++;}
        }
        return cnt;
    }
};