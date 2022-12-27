main(vector<vector<int>>a){
    for(int i=0;i<a.sie();i++){
        for(int j=0;j<a[0].size();j++){
            if(a[i][j]==-1){a[i][j]=1e9;}
            if(i==j){a[i][j]=0;}
        }
    }

     for(int k=0;k<a.size();k++){
        for(int i=0;i<a.size();i++){
            for(int j=0;j<a.size();j++){
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
            }
        }
     }


    for (int i = 0; i < a.size(); i++) {
			for (int j = 0; j < a[0].size(); j++) {
				if (a[i][j] == 1e9) {
					a[i][j] = -1;
				}
			}
		}
}


//For negetive cycle
for(int i=0;i<a.size();i++){if(a[i][i]<0){return "there is cycle";}}