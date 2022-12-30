//Leetcode
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
       const int n=grid.size();
        if (grid[0][0] == 0 && n == 1){ return 1;}
     
        if(grid[0][0]==1 || grid[n-1][n-1]==1){return -1;}
        
        vector<vector<int>>v(n,vector<int>(n,1e9));
        queue<pair<int,pair<int,int>>>q;
        q.push({1,{0,0}});
        v[0][0]=1;
        
        
        int dRow[8]={-1,-1,0,1,1,1,0,-1};
        int dCol[8]={0,1,1,1,0,-1,-1,-1};
        
        while(!q.empty()){
            int dis=q.front().first;
            int r=q.front().second.first;
            int c=q.front().second.second;
            q.pop();
           for(int i=0;i<8;i++){ 
                  int nr=r+dRow[i];
                  int nc=c+dCol[i];
               if(nr<n && nr>=0 && nc<n && nc>=0 && grid[nr][nc]==0 && dis+1<v[nr][nc]){
                        v[nr][nc]=dis+1;
                        if(nr==n-1 && nc==n-1){return dis+1;}
                        q.push({dis+1,{nr,nc}});
           }
                   
                    
                    
           }            
        }
        
       return -1; 
    }
};