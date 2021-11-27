//BFS:

#include <bits/stdc++.h>
using namespace std;

bool bipartiteBfs(int src, vector<int> adj[], int color[]) {
    queue<int>q;
    q.push(src); 
    color[src] = 1; 
    while(!q.empty()) {
        int node = q.front(); 
        q.pop();
        
        for(auto it : adj[node]) {
            if(color[it] == -1) {
                color[it] = 1 - color[node]; 
                q.push(it); 
            } else if(color[it] == color[node]) {
                return false; 
            }
        }
    }
    return true; 
}
bool checkBipartite(vector<int> adj[], int n) {
    int color[n];
    memset(color, -1, sizeof color); 
    for(int i = 0;i<n;i++) {
        if(color[i] == -1) {
            if(!bipartiteBfs(i, adj, color)) {
                return false;
            }
        }
    }
    return true; 
}
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> adj[n];
	for(int i = 0;i<m;i++) {
	    int u, v;
	    cin >> u >> v;
	    adj[u].push_back(v); 
	    adj[v].push_back(u); 
	}
	
	if(checkBipartite(adj, n)) {
	    cout << "yes"; 
	} else {
	    cout << "No"; 
	}
	return 0;
}

//DFS:
class Solution {
public:
      // here choose two color as 0 and 1
    bool dfs(vector<vector<int>>& graph, vector<int>v,int i){
        for(auto it:graph[i]){   //check for this adjacent
           
            
            if(v[it]==-1){
               v[it]=1-v[i];
               if(!dfs(graph,v,it)){return false; }
           }  
            else if(v[it]==v[i]){return false;}
        }
        return true;
    }
    
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();  //Take the Size of graph or find how many vertics are there.
        vector<int>v(n,-1); // make a navigation array. 
        
        for(int i=0;i<n;i++){  // start it with loop bcz there maybe multiple components and also intialize i=0 bcz the graph satrt from 0.
            
            if(v[i]==-1){
                v[i]==0;    // you can start it with 1 also
                if(dfs(graph,v,i)==false){
                    return false;
                }
            }
        }
        return true;
    }
};