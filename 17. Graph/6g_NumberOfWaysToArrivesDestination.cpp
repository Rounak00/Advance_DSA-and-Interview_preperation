class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod=(int)(1e9+7);
        vector<pair<int,int>>adj[n];
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        vector<int>way(n,0),dist(n,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        way[0]=1;
        dist[0]=0;
        
        while(!pq.empty()){
            int dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            for(auto it:adj[node]){
               int newnode=it.first;
                int w=it.second;
                
                if(dis+w<dist[newnode]){
                    dist[newnode]=dis+w;
                    pq.push({dis+w,newnode});
                    way[newnode]=way[node];
                }
                else if((dis+w)==dist[newnode]){
                    way[newnode]=(way[node]+way[newnode])%mod;
                }
            }
        }
        return (way[n-1])%mod;
    }
};