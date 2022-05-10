//Floor

int findFloor(vector<long long> v, long long n, long long x){
        using ll=long long;
        ll start = 0;
        ll end = n-1;
        ll mid = start + (end - start/2);
        ll ans = -1;
        
        
        while(start<=end)
        {
            if(x == v[mid]){
                return mid;
            }else if(x > v[mid]){
                ans = mid;
                start = mid + 1;
            }else if(x < v[mid]){
                end = mid - 1; 
            }
            mid = start + (end - start/2);
        }
        return ans;
        
    }

 //Ceil
 int findCeil(vector<long long> v, long long n, long long x){
        using ll=long long;
        ll start = 0;
        ll end = n-1;
        ll mid = start + (end - start/2);
        ll ans = -1;
        
        
        while(start<=end)
        {
            if(x == v[mid]){
                return mid;
            }else if(x > v[mid]){
                start = mid + 1;
            }else if(x < v[mid]){
                ans = mid;
                end = mid - 1; 
            }
            mid = start + (end - start/2);
        }
        return ans;
        
    }

