//DFS
class Solution {
  public:
  
    bool dfs(int node, int parent, int vis[], int V,vector<int> adj[]){
        vis[node]=1;
        
        for(auto it: adj[node]){
            if(!vis[it]){
                if(dfs(it,node,vis,V,adj)==true){return true;}
            }
            else if(it!=parent){return true;}
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
       int vis[V]={0};
       
       for(int i=0;i<V;i++){
           if(!vis[i]){
               if(dfs(i,-1,vis,V,adj)==true){
                   return true;
               }
           }
       }
       return false;
        
    }
};

//TC: O(components) + DFS
//SC: O(node) recursion time + o(Node) vis array

//BFS
class Solution {
  public:
  
    bool bfs(int node, int parent, int vis[],vector<int> adj[]){
        queue<pair<int, int>>q;
        q.push({node,parent});
        
        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            vis[node]=1;
            
            for(auto it: adj[node]){
               if(!vis[it]){
                   q.push({it,node});
               } 
               else if(it!=parent){
                   return true;
               }
            }
            
        }
        
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
       int vis[V]={0};
       
       for(int i=0;i<V;i++){
           if(!vis[i]){
               if(bfs(i,-1,vis,adj)==true){
                   return true;
               }
           }
       }
       return false;
        
    }
};

//TC: O(components) + BFS
//SC: O(node) queue size + o(Node) vis array
