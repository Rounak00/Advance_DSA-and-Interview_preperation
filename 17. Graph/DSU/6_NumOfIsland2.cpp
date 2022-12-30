class Dis{
    vector<int>par,size;
 public:
    Dis(int n){
        n=n+1; // n+1 will not affect work as a immergency
        par.resize(n);
        size.resize(n);
        for(int i=0;i<n;i++){
            par[i]=i;
            size[i]=1;
        }
    }
        int find(int n){
            if (n==par[n])return n;
            else return par[n]=find(par[n]);
        }
        
        void unions(int u, int v){
            int pu=find(u);
            int pv=find(v);
            if(pu==pv)return;
            if(size[pu]>size[pv]){
                par[pv]=pu;
                size[pu]+=size[pv];
            }
            else{
                par[pu]=pv;
                size[pv]+=size[pu];
            }
        }
    
};


class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &o) {
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
             int node=(r*m)+c;
             if(vis[r][c]==1){
                 ans.push_back(cnt);
                 continue;
                }
             vis[r][c]=1;
             cnt++;
             for(int i=0;i<4;i++){
                 int nr=r+dr[i];
                 int nc=c+dc[i];
                 int newnode=(nr*m)+nc;
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
    }
};