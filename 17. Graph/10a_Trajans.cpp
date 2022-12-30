//TC: V+2E
//bridges
class Solution {
private:
     int timer=1;
private:
     void dfs(int node, int parent, vector<int>&vis, int ti[],int lti[],vector<int>adj[],vector<vector<int>>&ans){
         vis[node]=1;
         ti[node]=lti[node]=timer;
         timer++;
         
         for(auto it:adj[node]){
             if(it==parent)continue;
             if(vis[it]){
                 lti[node]=min(lti[node],lti[it]);
             }
             if(!vis[it]){
                 dfs(it,node,vis,ti,lti,adj,ans);
                 lti[node]=min(lti[node],lti[it]);
                 if(lti[it]>ti[node]){ans.push_back({node,it});}
             }
         }
     }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>adj[n];
        
            for(auto it:connections){
                adj[it[0]].push_back(it[1]);
                adj[it[1]].push_back(it[0]);
            }
        
        
        vector<int>vis(n,0);
        int ti[n],lti[n]; //time of insertion and Lowest time of insertion array
        vector<vector<int>>ans;
        
        dfs(0,-1,vis,ti,lti,adj,ans);
        return ans;
    }
};