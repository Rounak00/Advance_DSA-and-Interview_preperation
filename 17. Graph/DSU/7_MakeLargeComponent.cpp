class Dis{
    
 public:
 vector<int>par,size;
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
    bool isValid(int row,int col,int n,int m){
        return  row>=0&&row<n&&col>=0&&col<m;
    }
    int MaxConnection(vector<vector<int>>& grid) {
       int n=grid.size();
       Dis d(n*n);
       
       int dr[4]={-1,0,1,0};
       int dc[4]={0,1,0,-1};
       
       for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
               if(grid[i][j]==0)continue;
               for(int dir=0;dir<4;dir++){
                 int nr=i+dr[dir];
                 int nc=j+dc[dir];
                 if(isValid(nr,nc,n,n) && grid[nr][nc]==1){
                     int node=(i*n)+j;
                     int adjnode=(nr*n)+nc;
                     d.unions(node,adjnode);
                 }
                   
               }
           }
       }
       int ans=0;
       for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
               if(grid[i][j]==1)continue;
               unordered_set<int>st;
               for(int dir=0;dir<4;dir++){
                   int nr=i+dr[dir];
                   int nc=j+dc[dir];
                   if(isValid(nr,nc,n,n) && grid[nr][nc]==1){
                       int node=i*n+j;
                       int adjnode=nr*n+nc;
                       st.insert(d.find(adjnode));
                   }
               }
               int val=0;
              for(auto it:st){
                   val+=d.size[it];
              }
              
              ans=max(ans, val+1);
           }
       }
       
       for(int cell=0;cell<n*n;cell++){
           ans=max(ans,d.size[d.find(cell)]);
       }
       return ans;
    }
};