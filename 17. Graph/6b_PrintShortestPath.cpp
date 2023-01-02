//Weighted undirected graph
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<vector<int>>adj[n+1];
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>pq;
        vector<int>dis(n+1,1e9),par(n+1);
        for(int i=0;i<n+1;i++){par[i]=i;}
        
        pq.push({0,1});
        dis[1]=0;
        
        while(pq.empty()==false){
            int node=pq.top().second;
            int w=pq.top().first;
            pq.pop();
            for(auto it:adj[node]){
                int adjn=it[0];
                int ew=it[1];
                if(w+ew<dis[adjn]){
                    dis[adjn]=w+ew;
                    par[adjn]=node;
                    pq.push({w+ew,adjn});
                }
            }
        }
        if(dis[n]==1e9){return {-1};}
        vector<int>ans;
        int node=n;
        while(par[node]!=node){
            ans.push_back(node);
            node=par[node];
            
        }
        ans.push_back(1);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};