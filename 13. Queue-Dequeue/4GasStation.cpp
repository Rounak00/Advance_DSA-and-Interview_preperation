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

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
int dep=0; //short of petrol
int balance=0; // extra petrol
int start=0;

    for(int i=0; i<gas.size(); i++){
        balance+=gas[i]-cost[i];
        
        if(balance<0){
            start=i+1;
            dep+=balance;
            balance=0;
        }
    }
    
    if(dep+balance>=0)
        return start;
    else
        return -1;
}
