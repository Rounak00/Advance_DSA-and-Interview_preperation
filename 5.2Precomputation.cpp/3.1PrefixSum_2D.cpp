int solve(vector<vector<int>>a){
    vector<vector<int>>pf;
    int n=pf.size(), int m=pf[0].size();
    pf[0][0]=a[0][0];
    for(int i=1;i<n;i++){
        pf[i][0]= a[i][0]+pf[i-1][0];
    }
    for(int i=1;i<m;i++){
        pf[0][i]= a[0][i]+pf[0][i-1];
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            pf[i][j]=a[i][j]+pf[i-1][j]+pf[i][j-1]-pf[i-1][j-1];
        }
    }


    //now assume there is quary like 2,2 - 3,3
    int l1=2,l2=2;
    int r1=3,r2=3;

    return  (pf[3][3]- pf[2-1][3]- pf[3][2-1] + pf[l1-1][l2-1])
}