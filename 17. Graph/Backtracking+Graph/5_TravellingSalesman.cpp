// NON EXICUTABLE

class Solution {
public:
int ans=INT_MAX;

void solve( vector<pair<int,int>>adj[],int n,int &current,vector<int>&vis,int count,int node){
   
    vis[node]=1;
    count++;
    if(count==n){
        if(adj[node][0].second!=0){
            ans=min(ans, adj[node][0].second+current);
        }
        vis[node]=0;
        return;
    }
    
    for(int i=0;i<adj[node].size();i++){
        if(adj[node][i].second!=0 && vis[(adj[node][i].first)]){
            current+=adj[node][i].second;
            solve(adj,n,current,vis,count,(adj[node][i].first));
            current-=adj[node][i].second;
        }
    }
    vis[node]=0;
    
}



int total_cost(vector<vector<int>>cost){
    int n=cost.size();
    vector<pair<int,int>>adj[n];
    
    for(int i=0;i<cost.size();i++){
        for(int j=0;j<n;j++){
           
                adj[i].push_back({j,cost[i][j]});
           
        }
    }
    vector<int>vis(n,0);
    int current=0;
    
     solve(adj,n,current,vis,0,0);
    
   return ans; 
}
};