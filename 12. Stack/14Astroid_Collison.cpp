class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        int n =a.size();
       stack<int>s;
    for(int i=0;i<n;i++){
        if(a[i]>0){s.push(a[i]);}
        else{
            //case 1 when top is lesser
            while(s.size() && s.top()>0 && s.top()<-(a[i])){
                s.pop();
            }
            //case 2 whem both are same
            if(s.size() && s.top()==-(a[i])){s.pop();}
            //case 3 when top is greater
            else if(s.size() && s.top()>-(a[i])){ /*do nothing simple ignore*/}
            //case 4 while its same left direction
            else{
                s.push(a[i]);
            }

        }

    }
    vector<int>res;
    while(!s.empty()){
        res.push_back(s.top());
        s.pop();
    }
    reverse(res.begin(),res.end());
    return res;
   }
};