class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& a) {
         int i=0;
        int n=a.size();
        vector<int>ans;
    while(i<n){
        int c=a[i]-1;
        if(a[i]!=a[c]){
            swap(a[i],a[c]);
        }
        else{
            i++;
        }
    }
        for(int i=0;i<n;i++){
            if(a[i]!=i+1){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};