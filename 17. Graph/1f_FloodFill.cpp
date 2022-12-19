//DFS
class Solution {
public:
    void dfs(int r, int c,int n, int m,int color, int source, vector<vector<int>>&mat ){
        if(r<0 || r>=n|| c<0 || c>=m || mat[r][c]==color || mat[r][c]!=source){return;}
        
        mat[r][c]=color;
        
        int delrow[4]={1,0,-1,0};
        int delcol[4]={0,1,0,-1};
        
        for(int i=0;i<4;i++){
            int newrow=r+delrow[i];
            int newcol=c+delcol[i];
            dfs(newrow,newcol,n,m,color,source,mat);
        }
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>&mat , int sr, int sc, int color) {
        int n=mat.size();
        int m=mat[0].size();
        int source=mat[sr][sc];
        
        dfs(sr,sc,n,m,color,source,mat);
        return mat;
    }
};


//TC: for each node O(N*M) + and their's neighbours O(N*M*4)
//SC: O(N*M) recursion call stack + vis array O(N*M)

//BFS
class Solution {
public:
    void bfs(int r, int c,int n, int m,int color, int source, vector<vector<int>>&mat ){
        queue<pair<int,int>>q;
        
        q.push({r,c});
        int delr[4]={1,0,-1,0};
        int delc[4]={0,1,0,-1};
        
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            
            mat[row][col]=color;
            for(int i=0;i<4;i++){
                int newrow=row+delr[i];
                int newcol=col+delc[i];
                
                if(newrow>=0 && newrow<n && newcol>=0 && newcol<m && mat[newrow][newcol]==source && mat[newrow][newcol]!=color){
                    q.push({newrow,newcol});
                }
            }
        }
        
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>&mat , int sr, int sc, int color) {
        int n=mat.size();
        int m=mat[0].size();
        int source=mat[sr][sc];
        
        bfs(sr,sc,n,m,color,source,mat);
        return mat;
    }
};

//TC: O()
//SC: O(n*m) for q