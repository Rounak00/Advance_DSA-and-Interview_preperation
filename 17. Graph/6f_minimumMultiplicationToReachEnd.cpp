class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
       vector<int>dist(100000,1e9);
       queue<pair<int,int>>q; //num,steps
       q.push({start,0});
       dist[start]=0;
       
       while(!q.empty()){
           int num=q.front().first;
           int st=q.front().second;
           q.pop();
           for(auto it:arr){
               int num=num*it;
               
               if(st+1<dist[num]){
                   dist[num]=st+1;
                   if(num==end)return st+1;
                   q.push({num,st+1});}
           }
       }
       return -1;
    }
};