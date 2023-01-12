// Leetcode 1443
//Time complexity: O(n)

class Solution {
public:
 
    int dfs(int start, int n, vector<vector<int>>& graph, vector<bool>& hasApple, vector<bool>& visited) {
        int time = 0, childTime;

        // For each adjacent unvisited node of start, perform dfs
        for(auto i: graph[start]) {
            if(!visited[i]) {
                // Calculating the child 'i' time 
                visited[i] = true;
                childTime = dfs(i, n, graph, hasApple, visited);

                // * childTime == 0 implies that the child 'i' does not have any apples
                // * If child 'i' has apples, then add it to the total time. 
                // * Add 2 to it as it takes +2 from 'i' to parent.
                if(childTime != 0 || hasApple[i])
                    time += (childTime + 2);
            }
        }

        return time;
    }
       
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<bool> visited(n, false);

        // Make Adjacency Graph
        vector<vector<int>> graph(n);
        for(auto& edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        // Visit 0 as it is the beginning
        visited[0] = true;
        return dfs(0, n, graph, hasApple, visited);
    }
    
};
