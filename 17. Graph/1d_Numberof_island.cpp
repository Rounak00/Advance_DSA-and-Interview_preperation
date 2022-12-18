// GFG BFS
class Solution {
public:
    void bfs(int r, int c, int n, int m,  vector<vector<int>>&vis, vector<vector<char>>&g){
        queue<pair<int,int>>q;
        q.push({r,c});
        vis[r][c]=1;
        
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            
            for(int delrow=-1;delrow<=1;delrow++){
                for(int delcol=-1;delcol<=1;delcol++){
                    int nrow=row+delrow;
                    int ncol=col+delcol;
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && g[nrow][ncol]=='1'&& vis[nrow][ncol]==0)
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
            
        }
    }
    int numIslands(vector<vector<char>>& g) {
        int n=g.size();
        int m=g[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt=0;
        for(int r=0;r<n;r++){
            for(int c=0;c<m;c++){
                if(!vis[r][c] && g[r][c]=='1'){
                    cnt++;
                    bfs(r,c,n,m,vis,g);
                }
            }
        }
        return cnt;
    }
};

//GFG DFS
void dfs(vector<vector<int>>vis,vector<vector<char>>& grid,int r,int c,int n,int m){
    if(r<0 || r>n-1 || c<0 || c>m-1 || grid[r][c]=='0' || vis[r][c]==1){return;}

    vis[r][c]=1;
    dfs(vis,grid,r-1,c-1,n,m);
    dfs(vis,grid,r-1,c,n,m);
    dfs(vis,grid,r-1,c+1,n,m);
    dfs(vis,grid,r,c-1,n,m);
    dfs(vis,grid,r,c+1,n,m);
    dfs(vis,grid,r+1,c-1,n,m);
    dfs(vis,grid,r+1,c,n,m);
    dfs(vis,grid,r+1,c+1,n,m);
}
int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]&&grid[i][j]=='1'){
                    count++;
                    dfs(vis,grid,i,j,n,m);
                }
            }
        }
        return count;
    }
};

//LEETcode
class Solution {

private:
void bfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>> grid,int n, int m)
{
    vis[row][col] = 1;
    queue<pair<int,int>> q;
    q.push({row,col});

    while(!q.empty())
    {
        row = q.front().first;
        col = q.front().second;
        q.pop();
        int delrow[] = {1,0,-1,0};
        int delcol[] = {0,-1,0,1};
        for(int i=0;i<4;i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]=='1')
            {
                vis[nrow][ncol] = 1;
                q.push({nrow,ncol});
            }
    }
    }

}

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int islands = 0;
        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]=='1')
                {
                    islands++;
                    bfs(i,j,vis,grid,n,m);
                }
            }
        }
        return islands;
    }
};


//leetcode DFS
class Solution {
public:
    void dfs(vector<vector<int>>&vis,vector<vector<char>>&grid,int i,int j){
        if(i>grid.size()-1 || j>grid[0].size()-1|| i<0 ||j<0 || grid[i][j]=='0' || vis[i][j]==1){
            return ;
        }
        vis[i][j]=1;
        dfs(vis,grid,i+1,j);
        dfs(vis,grid,i,j+1);
        dfs(vis,grid,i,j-1);
        dfs(vis,grid,i-1,j);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    count++;
                    dfs(vis,grid,i,j);
                }
            }
        }
        return count;
    }
};