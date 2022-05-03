//bettter approach
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix[0].size();
        int n=matrix.size();
        vector<int>r(n,-1);
        vector<int>c(m,-1);  
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    r[i]=0;
                    c[j]=0;
                }
            }
        }
          for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(r[i]==0||c[j]==0){
                    matrix[i][j]=0;
                }
            }
          }   
        
    }
};


//Efficient approach:
class Solution {
public:
    void setZeroes(vector<vector<int>>& a) {
        int n=a.size(); int m=a[0].size();
    int col=false;
        for(int i=0;i<n;i++){
            if(a[i][0]==0){col=true;}
            for(int j=1;j<m;j++){
                if(a[i][j]==0){
                a[i][0]=a[0][j]=0;
             }
            }
        }
        
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=1;j--){
                if(a[i][0]==0 || a[0][j]==0){
                    a[i][j]=0;
                }
            }
            if(col){a[i][0]=0;}
        }
    }
};