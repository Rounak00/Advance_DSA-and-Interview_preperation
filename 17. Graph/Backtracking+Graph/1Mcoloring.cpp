//Graph + Backtracking
class Solution{
public:
    
    bool isSafe(int node, int c,int size,int col[], bool graph[101][101] ){
        for(int k=0;k<size;k++){
            if(k!=node && graph[k][node]==1 && col[k]==c){
                return false;
            }
        }
        return true;
    }
    bool solve(int node,bool graph[101][101], int m, int n, int col[]){
        if(node==n)return true;
        
        for(int i=1;i<=m;i++){
            if(isSafe(node,i,n,col,graph)){
                col[node]=i;
                if(solve(node+1,graph,m,n,col))return true;
                col[node]=0;
            }
        }
        return false;
    }
    
    bool graphColoring(bool graph[101][101], int m, int n) {
       int col[n]={0};
       return solve(0,graph,m,n,col);
    }
    
};

//TC: O(N^M) for each node we try m colors so m combinations
//SC: O(N) color array + O(N) for recursion