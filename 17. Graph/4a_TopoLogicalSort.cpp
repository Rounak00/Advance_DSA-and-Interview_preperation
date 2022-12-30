//TC: same as DFS BFS -> V+E
//SC: same as DFS BFS -> V+E

//DFS
class Solution
{  private:
       void dfs(int node, int vis[],vector<int>adj[],stack<int>&s){
           vis[node]=1;
           
           for(auto it:adj[node]){
               if(!vis[it]){
                   dfs(it,vis,adj,s);
               }
           }
           s.push(node);
       }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	   int vis[V]={0};
	   stack<int>s;
	   for(int i=0;i<V;i++){
	       dfs(i,adj,vis,s);
	   }
	   
	   vector<int>ans;
	   while(!stack.empty()){
	       ans.push_back(stack.top());
	       stack.pop();
	   }
	   return ans;
	}
};


//BFS
class Solution {
public:
	vector<int> topo(int N, vector<int> adj[]) {
        queue<int> q; 
	    vector<int> indegree(N, 0); 
	    for(int i = 0;i<N;i++) {
	        for(auto it: adj[i]) {
	            indegree[it]++; 
	        }
	    }
	    
	    for(int i = 0;i<N;i++) {
	        if(indegree[i] == 0) {
	            q.push(i); 
	        }
	    }
	    vector<int> topo;
	    while(!q.empty()) {
	        int node = q.front(); 
	        q.pop(); 
	        topo.push_back(node);
	        for(auto it : adj[node]) {
	            indegree[it]--;
	            if(indegree[it] == 0) {
	                q.push(it); 
	            }
	        }
	    }
	    return topo;
	}
};