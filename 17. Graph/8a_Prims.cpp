struct myComp{
	    bool operator()(vector<int> &a, vector<int> &b){
	        return a[0] > b[0];
	    }
	};
	
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        int totalSum = 0;
        vector<vector<int>> mst;
        vector<bool> visited (V, false);
        priority_queue<vector<int>, vector<vector<int>>, myComp> pq;
        pq.push({0, 0, -1}); // {Priority queue will be having elements in the form of {wt, currNode, parentNode};
        while(pq.empty() == false){
            auto curr = pq.top();
            int node=curr[1];
            int weight=curr[0];
            int parent=curr[2];

            pq.pop();

            if(visited[node] == true){
                continue;
            }
            else{
                visited[node] = true;
                totalSum += weight;
                if(parent != -1){
                    mst.push_back({curr[2], curr[1]});
                }
                for(auto &e : adj[node]){
                          int wt=e[1];
                          int childnode=e[0]
                    if(visited[childnode] == false){
                        pq.push({wt, childnode, curr[1]});
                    }
                }
            }
        }
        return totalSum;
    }