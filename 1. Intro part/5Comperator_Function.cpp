  /*IN simple*/
   /*
    comperator function work like return false and we will change return true we will not change 
    */
  bool cmp(const int a,const int b){
    return a>b;
}

int main() {
    vector<int>a={2,7,1,8,4};
    sort(a.begin(),a.end(),cmp);
    for(int i:a){
        cout<<i<<" ";
    }
}
  
//Another way for sorting
struct MyComp {
        bool operator() (const int a, const int b) {
            return a>b;
        }
    };

int main() {
    vector<int>a={2,4,1,6,3};
    sort(a.begin(),a.end(),MyComp());
    for(auto it:a){cout<<it<<"";}
}  
  
  
//priority queue  
  struct MyComp {
        bool operator() (const pair<int, string>& a, const pair<int, string>& b) {
            if(a.first != b.first) {
                return a.first > b.first;//minheap
            }
            else {
                return a.second < b.second;//maxheap
            }
        }
    };
    priority_queue<pair<int, string>, vector<pair<int, string>>, MyComp> pq;


   