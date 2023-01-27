//we can also use queue bcz each time stop increase only 1 so its kinda bfs
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>dist(n,1e9);
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq; // <stops node dist>
        vector<pair<int,int>>adj[n];
        
        for(auto i:flights){
            adj[i[0]].push_back({i[1],i[2]});
        }
        pq.push({0,{src,0}});
        dist[src]=0;
        
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int node=it.second.first;
            int st=it.first;
            int dis=it.second.second;
            
            if(st>k)continue;
            for(auto ait:adj[node]){
                int nnode=ait.first;
                int wt=ait.second;
                
                if(st<=k && dis+wt<dist[nnode]){
                    dist[nnode]=dis+wt;
                    pq.push({st+1,{nnode,dis+wt}});
                }
            }
        }
        if(dist[dst]==1e9)return -1;
        return dist[dst];
    }
};