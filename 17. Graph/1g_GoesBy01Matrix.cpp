class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n =mat.size();
        int m=mat[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>ans(n,vector<int>(m,0));
        
        queue<pair<pair<int,int>,int>>q;
        
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(mat[i][j]==0){
                        q.push({{i,j},0});
                        vis[i][j]=1;
                    }
                }
            }
        int delr[4]={1,0,-1,0};
        int delc[4]={0,-1,0,1};
        
        while(!q.empty()){
            int row=q.front().first.first;
            int col= q.front().first.second;
            int dis= q.front().second;
            q.pop();
            ans[row][col]=dis;
            
            for(int i=0;i<4;i++){
                int nr= row+delr[i];
                int nc= col+delc[i];
                
                if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]==0){
                    q.push({{nr,nc},dis+1});
                    vis[nr][nc]=1;
                }
            }
        
        }
        return ans;
    }
};

TC: NXM + NxMx4
SC: NxM