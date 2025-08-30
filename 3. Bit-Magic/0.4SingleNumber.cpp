
//1. All number comes twice and one comes once TC:O(n)

res=0;
for(int i=0;i<n;i++){
    res= res^v[i]
}


//2. Single number 2 -> all comes 3 time and one comes once
int ans=0;
for(int bitInd=0;bitInd<=31;bitInd++){
    int cnt=0;
    for(int i=0;i<n;i++){
        if(v[i]&(1<<bitInd)) cnt++;
    }
    if(cnt%3==1) ans=ans|(1<<bitInd);
}

//better approach
for(i=1;i<n;i+3){
    if(v[i-1]!=v[i]) return v[i-1];
}
return v[n-1];