vector<int> solution(int v, vector<int>adj){
    bool vis[v];// bcz 0 based indexing
    for(int i=0;i<v;i++){
        v[i]=0;
    }

    vector<int>ans;
    queue<int> q;
    vis[0]=1;
    q.push(0);
    
    while(!q.empty()){ //for component graph we should rap it under the 
        int node=q.front();
        q.pop();
        ans.push_back(node);

        for(auto it: adj[node]){
            if(!vis[node]){
                vis[it]=1;
                q.push(it);
            }
        }
    }
    return ans;
}

// for component graph
vector < int > bfsOfGraph(int V, vector < int > adj[]) {
      vector < int > bfs;
      vector < int > vis(V, 0);
      for(int i=0;i<V;i++){ 
        if(!vis[i]){ 
            queue < int > q;
            q.push(i);
            vis[i] = 1;
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                bfs.push_back(node);

                for (auto it: adj[node]) {
                  if (!vis[it]) {
                      q.push(it);
                      vis[it] = 1;
                  }
                }
            }
          }
      }
      return bfs;
    }

    //TC(N+2E) -> for each node N we have all its neighbour (degree) so total number of degree we know 2*edge so 2E
    //SC(3N) -> queue + ans + vis 