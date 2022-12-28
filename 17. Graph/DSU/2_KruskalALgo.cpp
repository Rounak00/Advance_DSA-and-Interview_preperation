//TC: O(N+E) for edges+ O(n log n) for sort


class Dis{
    vector<int>par,size;
  public: 
     Dis(int n){
        par.resize(n);
        size.resize(n);
        for(int i=0;i<n;i++){
            par[i]=i;
            size[i]=1;
        }
    }
    int find(int n){
        if(n==par[n])return n;
        else{
            return par[n]=find(par[n]);
        }
    }
    void unions(int u, int v){
        int pu=find(u);
        int pv=find(v);
        
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

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int n, vector<vector<int>> adj[])
    {
        vector<pair<int, pair<int,int>>>edges;
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                int u=i;
                int v=it[0];
                int w=it[1];
                
                edges.push_back({w,{u,v}});
            }
        }
        Dis ds(n);
        sort(edges.begin(),edges.end());
        int ans=0;
        for(auto it:edges){
             int w=it.first;
             int u=it.second.first;
             int v=it.second.second;
             
             if(ds.find(u)!=ds.find(v)){
                 ans+=w;
                 ds.unions(u,v);
             }
        }
        return ans;
    }
};