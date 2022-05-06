class Solution {
public:
    int findMin(vector<int>& v) {
          int n = v.size();

    if(n==1)
        return v[0];
    int start(0), last(n-1);

    while(start<=last){
       
        if(v[start]<v[last]){ //extra case bcz in leetcode question it asked for minimum element in an array; just a slight variation
            return v[start];
        }
        int mid = start+(last-start)/2;
        int p=(mid+n-1)%n;
        int next=(mid+1)%n;
        if(v[start]>=v[mid] && v[mid]>=v[last]){
            return v[last];
        }
       
        if(v[mid]<=v[p] && v[mid]<=v[next]){
            return v[mid];
        }else if(v[mid]<=v[last]){
            last = mid;
        }else if(v[start]<=v[mid]){
            start = (mid+1)%n;
        }

    }
    return -1;

}
    
};