// E LOG V
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>ds(n,vector<int>(m,1e9));
        ds[0][0]=0;
        pq.push({0,{0,0}});
        
        int delr[4]={-1,0,1,0};
        int delc[4]={0,-1,0,1};
        
        while(!pq.empty()){
            int ef=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();
            if(r==n-1 && c==m-1){return ef;}
            
            for(int i=0;i<4;i++){
                int nr=r+delr[i];
                int nc=c+delc[i];
                
                if(nr>=0 && nr<=n-1 && nc>=0 && nc<=m-1){
                    int newefforts=max(ef,abs(mat[r][c]-mat[nr][nc]));
                    if(newefforts<ds[nr][nc]){ds[nr][nc]=newefforts; pq.push({newefforts,{nr,nc}});}
                }
            }
        }
        return 0;
    }
};