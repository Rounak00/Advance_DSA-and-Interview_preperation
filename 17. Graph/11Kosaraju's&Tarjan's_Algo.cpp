#include <bits/stdc++.h>
using namespace std;
void dfs(int node, stack<int> &st, vector<int> &vis, vector<int> adj[]) {
    vis[node] = 1; 
    for(auto it: adj[node]) {
        if(!vis[it]) {
            dfs(it, st, vis, adj); 
        }
    }
    
    st.push(node); 
}
void revDfs(int node, vector<int> &vis, vector<int> transpose[]) {
    cout << node << " "; 
    vis[node] = 1; 
    for(auto it: transpose[node]) {
        if(!vis[it]) {
            revDfs(it, vis, transpose); 
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m; 
	vector<int> adj[n]; 
	for(int i = 0;i<m;i++) {
	    int u, v;
	    cin >> u >> v; 
	    adj[u].push_back(v);
	}
	
	stack<int> st;
	vector<int> vis(n, 0); 
	for(int i = 0;i<n;i++) {
	    if(!vis[i]) {
	        dfs(i, st, vis, adj); 
	    }
	} 
	
	vector<int> transpose[n]; 
	
	for(int i = 0;i<n;i++) {
	    vis[i] = 0; 
	    for(auto it: adj[i]) {
	        transpose[it].push_back(i); 
	    }
	}
	
	
	
	while(!st.empty()) {
	    int node = st.top();
	    st.pop(); 
	    if(!vis[node]) {
	        cout << "SCC: "; 
	        revDfs(node, vis, transpose); 
	        cout << endl; 
	    }
	}
	
	
	return 0;
}



//Tarjan's algo:
#include<iostream> 
#include <list> 
#include <stack> 
#define NIL -1 
using namespace std; 


class Graph 
{ 
	int V; 
	list<int> *adj; 

	void SCCUtil(int u, int disc[], int low[], stack<int> *st, bool stackMember[]); 
public: 
	Graph(int V); 
	void addEdge(int v, int w); 
	void SCC(); 
}; 

Graph::Graph(int V) 
{ 
	this->V = V; 
	adj = new list<int>[V]; 
} 

void Graph::addEdge(int v, int w) 
{ 
	adj[v].push_back(w); 
} 


void Graph::SCCUtil(int u, int disc[], int low[], stack<int> *st, bool stackMember[]) 
{ 
	static int time = 0; 

	disc[u] = low[u] = ++time; 
	st->push(u); 
	stackMember[u] = true; 
 
	list<int>::iterator i; 
	for (i = adj[u].begin(); i != adj[u].end(); ++i) 
	{ 
		int v = *i;

		if (disc[v] == -1) 
		{ 
			SCCUtil(v, disc, low, st, stackMember); 

			low[u] = min(low[u], low[v]); 
		} 

		else if (stackMember[v] == true) 
			low[u] = min(low[u], disc[v]); 
	} 

	int w = 0;
	if (low[u] == disc[u]) 
	{ 
		while (st->top() != u) 
		{ 
			w = (int) st->top(); 
			cout << w << " "; 
			stackMember[w] = false; 
			st->pop(); 
		} 
		w = (int) st->top(); 
		cout << w << "\n"; 
		stackMember[w] = false; 
		st->pop(); 
	} 
} 

void Graph::SCC() 
{ 
	int *disc = new int[V]; 
	int *low = new int[V]; 
	bool *stackMember = new bool[V]; 
	stack<int> *st = new stack<int>(); 

	for (int i = 0; i < V; i++) 
	{ 
		disc[i] = NIL; 
		low[i] = NIL; 
		stackMember[i] = false; 
	} 

	for (int i = 0; i < V; i++) 
		if (disc[i] == NIL) 
			SCCUtil(i, disc, low, st, stackMember); 
} 

int main() 
{ 
	cout << "SCCs in the graph \n"; 
	Graph g(5); 
	g.addEdge(1, 0); 
	g.addEdge(0, 2); 
	g.addEdge(2, 1); 
	g.addEdge(0, 3); 
	g.addEdge(3, 4); 
	g.SCC(); 

	return 0; 
} 
