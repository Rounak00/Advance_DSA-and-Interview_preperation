// adjacent matrix:
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m; 
	
	// declare the adjacent matrix 
	int adj[n+1][n+1]; //take n and m if vertics starts from 0;
	
	// take edges as input 
	for(int i = 0;i<m;i++) {
	    int u, v; 
	    cin >> u >> v;
	    adj[u][v] = 1; 
	    adj[v][u] = 1; 
	}
	return 0;
}

//adjacent array of vectors:(we can do array of list also)
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m; 
	
	// declare the adjacent matrix 
	vector<int> adj[n+1]; // make this vector<pair<int,int>>a[n+1]; for weighted graph
	
	// take edges as input 
	for(int i = 0;i<m;i++) {
	    int u, v; 
	    cin >> u >> v;
	    adj[u].push_back(v); 
	    adj[v].push_back(u); // omit this line if its a directed graph
	}
	return 0;
}