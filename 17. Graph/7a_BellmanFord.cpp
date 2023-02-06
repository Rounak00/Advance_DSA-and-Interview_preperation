main(int s,vector<vector<int>edges,int n){
    vector<int>dist(n,1e9);
     dist[s]=0;
    for(int i=0;i<n-1;i++){
        for(auto it:edges){
             int u=it[0];
             int v=it[1];
             int w=it[2];

             if(dist[u]!=1e9 && dist[u]+wt < dist[v]){dist[v]=dist[u]+wt;}
        }
    }
    
    //for negetive cycle
    for(auto it:edges){
        int u=it[0];
        int v=it[1];
        int w=it[2];

        if (dist[u] != 1e9 && dist[u] + wt < dist[v]) {
				return "there is a cycle";
			}
    }
}
