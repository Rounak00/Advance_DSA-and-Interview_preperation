// First make two arrays maxl and maxr
// store max from each side in this arrays


//after that make a min array and store min of maxr  and maxl

// after that  now subtract arr of buildings to min array and then ad all value of that so you get ans

function(arr[], n){
    int maxl[n], maxr[n];
    maxl[0]=arr[0];
    mar[n-1]=arr[n-1];
    for(int i=1;i<n;i++){
     maxl[i]=max(max[i-1],arr[i]);
    }

     for(int i=n-2;i>=0;i--){
     maxl[i]=max(max[i+1],arr[i]);
    }
   
   int mina[n];
    for(int i=0;i<n;i++){
        mina[i]=min(maxl[i],maxr[i]);
    }

    int res[n];
    for(int i=0;i<n;i++){
        res[i]=mina[i]-arr[i];
    }

    int result;
    for(int i=0;i<n;i++){
      result+=res[i];
    }
    return result;
}