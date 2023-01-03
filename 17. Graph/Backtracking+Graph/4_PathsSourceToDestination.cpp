class Solution {

public:     
void DFS(vector<int>adj[],vector<vector<int>>& ans, vector<int>&temp,int src,int des){
        if(src==des){
            ans.push_back(temp);
            return ;
        }
   
        for(int i=0;i<adj[src].size();i++){
            temp.push_back(adj[src][i]);
            DFS(adj,ans,temp,adj[src][i],des);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool>visited(n,false);
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            for(auto it:graph[i]){
                adj[i].push_back(it);
            }
        }
        vector<vector<int>>ans;
        vector<int>temp;
        temp.push_back(0);
        
        DFS(adj,ans,temp,0,n-1);
        return ans;
    }
};