//Naive:

function(petrol[],dist[],n){
    for(int start=0;start<n;start++){
        int end=start;
        int curp=0;
        while(true){
            curp+=(petrol[end]-dist[end]);
            if(curp<0){break;}
            end=(end+1)%n;
            if(end==start){return start+1;}
        }
    }
}

//Efficient:

function(petrol[],dis[],n){
    int start=0;cur=0; pre=0;
    
    for(int i=0;i<n-1;i++){
        cur=(petrol[i]-dis[i]);
        if(cur<0){
            start=i+1;
            pre+=cur;
            cur=0
        }

    }
    return (pre+cur)>=0? start+1:-1;
}