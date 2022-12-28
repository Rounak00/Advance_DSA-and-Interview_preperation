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
            pq.pop();
            if(visited[curr[1]] == true){
                continue;
            }
            else{
                visited[curr[1]] = true;
                totalSum += curr[0];
                if(curr[2] != -1){
                    mst.push_back({curr[2], curr[1]});
                }
                for(auto &e : adj[curr[1]]){
                    if(visited[e[0]] == false){
                        pq.push({e[1], e[0], curr[1]});
                    }
                }
            }
        }
        return totalSum;
    }