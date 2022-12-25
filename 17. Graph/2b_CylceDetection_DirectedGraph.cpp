// BFS simple topo sort and if it will not same size as node then there  is cycle



//TC: V+E
//SC: 2n

// DFS

class Solution {
  public:
  
    bool dfs(int node, int vis[], int pat[],vector<int>adj[]){
        vis[node]=1;
        pat[node]=1;
        
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it, vis, pat, adj)==true)return true;
                
            }
            else if(pat[it]){return true;}
        }
        pat[node]=0;
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        int vis[V]={0};
        int pat[V]={0};
        
        for(int i=0;i<V;i++){
            if(!vis[i]){ 
                if(dfs(i,vis,pat,adj))return true;
            }
        }
        return false;
    }
};