int main(vector<vector<int>>adj[],int n, int src){
    int dist[n]={0};
    queue<int>q;
    q.push({src,0});
    disr[src]=0;

    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto it:adj[node]){
            if(dist[it]>dist[node]+1){
                dist[it]=dis+1;
                q.push({it,dis+1});
            }
        }
    }
    return dist;

}