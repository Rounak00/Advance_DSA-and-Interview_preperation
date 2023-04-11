void dfs(node,adj,vis,ans){
    vis[node]=1;
    ans.push_back(node);

    for(auto it: adj[node]){
        if(!vis[it]){
            dfs(it,vis,adj,ans);
        }
    }

}

vector < int > bfsOfGraph(int V, vector < int > adj[]) {
      vector < int > ans;
      vector < int > vis(V, 0);
       
       dfs(0,adj,vis,ans);

    }

//component Graph
void dfs(node,adj,vis,ans){
    vis[node]=1;
    ans.push_back(node);

    for(auto it: adj[node]){
        if(!vis[it]){
            dfs(it,vis,adj,ans);
        }
    }

}

vector < int > bfsOfGraph(int V, vector < int > adj[]) {
      vector < int > ans;
      vector < int > vis(V, 0);
       
       for(int i=0;i<v;i++){
        if(!vis[i])
          {dfs(0,adj,vis,ans);}
       }

    }    
//TC same
// SC= o(3N) -> recursion + vis array + ans