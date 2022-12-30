Dis d(n*m);
        int vis[n][m];
        memset(vis,0,sizeof vis);
        vector<int>ans;
        int cnt=0;
         int dr[4]={1,0,-1,0};
         int dc[4]={0,-1,0,1};
         for(auto it: o){
             int r=it[0];
             int c=it[1];
             int node=(r*n)+c;
             if(vis[r][c]){
                 ans.push_back(cnt);
                 continue;
                }
             vis[r][c]=1;
             cnt++;
             for(int i=0;i<4;i++){
                 int nr=r+dr[i];
                 int nc=c+dc[i];
                 int newnode=(nr*n)+nc;
                 if(nr<n && nr>=0 && nc<m && nc>=0 && vis[nr][nc]==1){
                    if(d.find(node)!=d.find(newnode)){
                        d.unions(node,newnode);
                        cnt--;
                    }
                 }
             }    
             ans.push_back(cnt);

         }


        return ans;