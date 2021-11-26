//Normal DFS
#include<bits/stdc++.h> 
using namespace std; 

void DFSRec(vector<int> adj[], int s, bool visited[]) 
{ 	
    visited[s]=true;
    cout<< s <<" ";
    
    for(int u:adj[s]){
        if(visited[u]==false)
            DFSRec(adj,u,visited);
    }
}

void DFS(vector<int> adj[], int V, int s){
    bool visited[V]; 
	for(int i = 0;i<V; i++) 
		visited[i] = false;
		
    DFSRec(adj,s,visited);
}

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() 
{ 
	int V=5;
	vector<int> adj[V];
	addEdge(adj,0,1); 
	addEdge(adj,0,2); 
	addEdge(adj,2,3); 
	addEdge(adj,1,3); 
	addEdge(adj,1,4);
	addEdge(adj,3,4);

	cout << "Following is Depth First Traversal: "<< endl; 
	DFS(adj,V,0); 

	return 0; 
} 
//disconnected
#include<bits/stdc++.h> 
using namespace std; 

void DFSRec(vector<int> adj[], int s, bool visited[]) 
{ 	
    visited[s]=true;
    cout<< s <<" ";
    
    for(int u:adj[s]){
        if(visited[u]==false)
            DFSRec(adj,u,visited);
    }
}

void DFS(vector<int> adj[], int V){
    bool visited[V]; 
	for(int i = 0;i<V; i++) 
		visited[i] = false;
		
    for(int i=0;i<V;i++){
        if(visited[i]==false)
            DFSRec(adj,i,visited);
    }
}

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() 
{ 
	int V=5;
	vector<int> adj[V];
	addEdge(adj,0,1); 
	addEdge(adj,0,2); 
	addEdge(adj,1,2);
	addEdge(adj,3,4);

	cout << "Following is Depth First Traversal for disconnected graphs: "<< endl; 
	DFS(adj,V); 

	return 0; 
} 


// For finding connected components
#include<bits/stdc++.h> 
using namespace std; 

void DFSRec(vector<int> adj[], int s, bool visited[]) 
{ 	
    visited[s]=true;
    
    for(int u:adj[s]){
        if(visited[u]==false)
            DFSRec(adj,u,visited);
    }
}

int DFS(vector<int> adj[], int V){
    int count=0;
    bool visited[V]; 
	for(int i = 0;i<V; i++) 
		visited[i] = false;
		
    for(int i=0;i<V;i++){
        if(visited[i]==false)
            {DFSRec(adj,i,visited);count++;}
    }
    return count;
}

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() 
{ 
	int V=5;
	vector<int> adj[V];
	addEdge(adj,0,1); 
	addEdge(adj,0,2); 
	addEdge(adj,1,2);
	addEdge(adj,3,4);

	cout << "Number of connected components: "<< DFS(adj,V); 

	return 0; 
} 
//TC: O(v+e)