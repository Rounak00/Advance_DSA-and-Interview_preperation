//withou convert into list
class Solution {
public:
    
    
    void dfs(vector<vector<int>>& isConnected,vector<bool>& vis,int num,int n){
        vis[num]=true;
        for(int i=0;i<n;i++){
            if(isConnected[num-1][i]==1&&!vis[i+1]){
                dfs(isConnected,vis,i+1,n);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
       int n=isConnected.size();
        int count=0;
        vector<bool>vis(n+1,false);
        for(int i=1;i<n+1;i++){
            if(!vis[i]){
                dfs(isConnected,vis,i,n);
                count++;
            }
        }
        return count;
    }
};


// convert matrix to list solution
class Solution {
private:
    void dfs(int node , vector<int> adjLs[] , vector<int> &vis){
        vis[node] = 1;
        for(auto it : adjLs[node]){
            if(!vis[it]){
                dfs(it , adjLs , vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adjLs[n];
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && isConnected[i][j]==1) {
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }
        
        int count = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                count++;
                dfs(i ,adjLs , vis);
            }
        }
        return count;
    }
};