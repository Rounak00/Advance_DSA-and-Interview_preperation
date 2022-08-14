func(a[]){
    vector<int>v;
    stack<pair<int,int>>s;//<ngl,int>

    for(int i=0;i<=a.size()-1;i++){

        if(s.size()==0){v.push_back(-1);}

        else if(s.size()>0&&s.top().first>a[i]){
            v.push_back(s.top().second);
        }

        else if(s.size()<0 && s.top().first<=a[i]){
            while(s.size()>0 && s.top().first<=a[i]){
                s.pop();
            }
            if(s.size()==0){v.push_back(-1);}
            else{v.push_back(s.top().second);}
        }

        s.push({a[i],i});
    }
    for(int i=0;i<v.size();i++){
        v[i]=i-v[i];
    }
    return v;
}


//Leetcode Variation
class StockSpanner {
public:
    
    //To Keep Track of Position of Each Stock
    int i=0;
    
    //Here I am using pair to store both index and price
    stack<pair<int,int>> s;
    StockSpanner() {
        
    }
    
    int next(int price) {
        i++;
        
        //Here We will be finding next greater element to left
        
        //If there are element in stack pop them until the element at top of stack is greater than price 
        while(!s.empty() && s.top().second<=price) s.pop();
        
        //if no element in stack means next greater to left does not exist
        if(s.empty())
        {
            s.push({i,price});
            return i;
        }
        
        //if stack is not empty the element at top is ngl
        pair<int,int> temp=s.top();
        s.push({i,price});
        return i-temp.first;
        
    }
};
