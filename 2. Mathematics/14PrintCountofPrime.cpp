// given a querie of L and R range and need to find how many prime numbers are there

//Approach -> make a sieve array and then precompute the count

vector<int> getSieve(int N){
    vector<int>arr(N+1,1);
    arr[0]=arr[1]=0;

    for(int i=2;i*i<=N;i++){ 
        if(arr[i]){
          for(int j=i*i; j<=N; j+=i){
            arr[j]=0;
          }
        }
    }
    return arr;
}

vector<int> precompute(vector<int>arr){
    int count =0;
    for(int i=0;i< arr.size();i++){
       count+=arr[i];
       arr[i]=count;
    }
    return arr;
}

int main(vector<pair<int,int>>query){
    vector<int>prime=getSieve(1e6);
    precompute(prime);
    for (auto Q : query) {
        int l = Q.first, r = Q.second;
        cout << "Prime count between " << l << " and " << r << " = "
             << prime[r] - prime[l - 1] << endl; // Prime count in range
    }

    return 0;
}