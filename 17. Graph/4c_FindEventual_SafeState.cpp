//DFS + Detect cycle
bool dfs(int node, vector<int>adj[],int vis[],int path[],int check[]){
    vis[node]=1;
    path[node]=1;
    check[node]=0;

    for(auto it:adj[node]){
        if(!vis[it]){
           if(dfs(it,adj,vis,path,check)==true){
            return true;
           }
        }
        else if(path[it]){
            check[node]=0;
            return true;
        }
    }
    check[node]=1;
    path[node]=0;
    return false;
}



vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
		int vis[V] = {0};
		int pathVis[V] = {0};
		int check[V] = {0};
		vector<int> safeNodes;
		for (int i = 0; i < V; i++) {
			if (!vis[i]) {
				dfsCheck(i, adj, vis, pathVis, check);
			}
		}
		for (int i = 0; i < V; i++) {
			if (check[i] == 1) safeNodes.push_back(i);
		}
		return safeNodes;
	}


//BFS (TOPO SORT)

vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
    vector<int>a[V];
    int ind[V]={0};
    for(int i=0;i<V;i++){
        for(auto it:adj[i]){
            a[it].push_back(i);
            ind[i]++;
        }
    }
    vector<int>ans;
    queue<int>q;
    
    for(int i=0;i<V;i++){if(ind[i]==0){q.push(i);}}

    while(!q.empty()){
        int node=q.front();q.pop();
        ans.push_back(node);

        for(auto it:adj[node]){
            ind[it]--;
            if(ind[it]==0){q.push(it);}
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
    
}