class myComparator {
  public:
    bool operator() (const pair<int,int> &p1, const pair<int,int> &p2) {
      if(p1.first == p2.first) return p1.second < p2.second; //leesthan -> max heap
      
      return p1.first > p2.first;//greater than -> min heap
    }};
int main() {
   priority_queue<pair<int,int>,vector<pair<int,int>>,myComparator>p;
    p.push({1,2});
    p.push({2,1});
    
    cout<<p.top().first<<" "<<p.top().second<<endl;
    p.push({1,3});
    cout<<p.top().first<<" "<<p.top().second;
}