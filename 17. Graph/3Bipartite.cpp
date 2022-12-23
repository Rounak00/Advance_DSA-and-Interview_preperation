//BFS
class Solution {
public:
    bool bfs(vector<vector<int>>& graph, vector<int>&v, int node){
        queue<int>q; 
        q.push(node);
        v[node]==0;    
        while(q.empty()==false){        
           int u=q.front(); q.pop();
           
           for(auto it:graph[u]){  
              
               if(v[it]==-1){v[it]=1-v[u]; q.push(it);}  
                else if(v[u]==v[it]){return true;} 
           } 
        }
        return false;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size(); 
        vector<int>v(n,-1); 
        
        for(int i=0;i<n;i++){ 
            if(v[i]==-1){
                if(bfs(graph,v,i)==true){
                    return false;
                }
            }
        }
        return true; 
    }
};


//DFS
class Solution {
public:
  bool dfs(int node, int color,vector<vector<int>>& graph, vector<int>&vis){
        vis[node]=color;

        for(auto it:graph[node]){
            if(!vis[it]){
               if(dfs(it,!color,graph,vis)==false){return false;}
            }
            else if(color==vis[it]){return false;}
        }
        return true;
    }
  bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size(); 
        vector<int>v(n,-1); 
        
        for(int i=0;i<n;i++){ 
            if(v[i]==-1){
                if(dfs(i,0,graph,v)==true){
                    return false;
                }
            }
        }
        return true; 
    }
};
//time and space complexity same as BFS and DFS