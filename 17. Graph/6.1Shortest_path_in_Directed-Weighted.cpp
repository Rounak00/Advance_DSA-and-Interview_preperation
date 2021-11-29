// directed but acycilic
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {

public:
    bool checkForCycle(int s, int V, vector<int> adj[], vector<int>& visited)
    {
        vector<int> parent(V, -1);
     
        // Create a queue for BFS
        queue<pair<int,int>> q;
     
        visited[s] = true;
        q.push({s, -1});
     
        while (!q.empty()) {
     
            int node = q.front().first;
            int par = q.front().second;
            q.pop();
     
            for (auto it : adj[node]) {
                if (!visited[it]) {
                    visited[it] = true;
                    q.push({it, node});
                }
                else if (par != it)
                    return true;
            }
        }
        return false;
    }
public:
	bool isCycle(int V, vector<int>adj[]){
	    vector<int> vis(V, 0); 
	    for(int i = 0;i<V;i++) {
	        if(!vis[i]) {
	            if(checkForCycle(i, V, adj, vis)) return true; 
	        }
	    }
	    
	    return false; 
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isCycle(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends


////In youtube channel explanation

void findtopo(int i, int vis[], stack<int>&st, vector<int>&adj[]){
	vis[i]=1;
	for(auto it:adj[i]){
		if(vis[it.first]==0){
			findtopo(it.first,vis,st,adj);
		}
	}
	st.push(i);
}


shortestpath(int s,int n,vector<pair<int,int>>adj[]){
 int in=INT_MAX;
  int vis[n]={0};
   stack<int>st;
   for(int i=0;i<n;i++){
	   if(!vis[i]){
		   findtopo(i,vis,st,adj);
	   }
   }

   int dist[n];
   for(int i=0;i<n;i++){
	   dist[i]=in;
   }
   dist[s]=0;//s is source;

   while(!st.empty()){
	   int node=st.top(); st.pop();

	   if(dist[node]==in){
		   for(auto it:adj[node]){
			   if(dist[node]+it.second<dist[it.first]){
				   dist[it.first]=dist[node]+it.second;
			   }
		   }
	   }
   }
   //print distance

}


int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n,m;
		cin>>n>>m;
		vector<pair<int,int>>adj[n];
		for(int i=0;i<m;i++){
			int u,v,w;
			cin>>u>>v>>w;
			adj[u].push_back({v,w});
			
		}
		shortestpath(0,n,adj);
	}
	return 0;