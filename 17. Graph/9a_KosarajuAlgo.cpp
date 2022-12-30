//tc: V+E 
//only on directed Graph
//Strong Connected Component (SCC); 
class Solution
{
	public:
	void dfs(int node,vector<int>&vis,vector<int>radj[]){
	    vis[node]=1;
	    
	    for(auto it:radj[node]){
	        if(!vis[it]){
	            dfs(it,vis,radj);
	        }
	    }
	}
	void dfs_st(int node, vector<int>&vis, vector<int>adj[],stack<int>&st){
	    vis[node]=1;
	    
	    for(auto it:adj[node]){
	        if(!vis[it]){
	            dfs_st(it,vis,adj,st);
	        }
	    }
	    st.push(node);
	}
	
	//Function to find number of strongly connected components in the graph
    int kosaraju(int V, vector<int> adj[])
    {
        vector<int>vis(V,0);
        stack<int>st;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs_st(i,vis,adj,st);
            }
        }
        
        vector<int>radj[V];
        
        for(int i=0;i<V;i++){
            vis[i]=0;
            for(auto it:adj[i]){
              radj[it].push_back(i);  
            }
        }
        int ans=0;
        
        while(!st.empty()){
            int node=st.top(); st.pop();
            if(!vis[node]){
                ans++;
                dfs(node,vis,radj);
            }
        }
        return ans;
    }
};

//for print paths it easy simply

vector<vector<int>>ans;
vector<int>t;
        while(!st.empty()){
            int node=st.top(); st.pop();
            if(!vis[node]){
                
                dfs(node,vis,radj,t);
                ans.push_back(t);
                t.clear();
            }
        }

dfs(int node,vector<int>&vis,vector<int>radj[],vector<int>&t){
    vis[node]=1;
    t.push_back(node);
    for(auto it:radj[node]){
        if(vis[it]==0){
            dfs(it,vis,radj,t);
        }
    }
}        