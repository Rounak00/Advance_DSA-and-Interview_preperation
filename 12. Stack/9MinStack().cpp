//naive:

#include <bits/stdc++.h>
using namespace std;

struct MyStack {
 
    stack<int> ms;
    stack<int> as;
 
void push(int x) {
 
      if(ms.empty() ) {
          ms.push(x);as.push(x);return;
      }
      
      ms.push(x);
      
      if(as.top()>=ms.top())
        as.push(x);
   }
 
void pop() {
 
    if(as.top()==ms.top())
        as.pop();
    ms.pop();
    
   }

int top() {
     return ms.top();
   }
 
int getMin() {
      return as.top();
   }
};

int main()
{
    MyStack s;
    s.push(4);
    s.push(5);
    s.push(8);
    s.push(1);
    s.pop();
 
    cout<<" Minimum Element from Stack: " <<s.getMin();
  
    return 0; 
}


//Efficient:
class MinStack {
public:
/** initialize your data structure here. */
stack<long> lifo;
long minn;

MinStack() {
    
}

void push(int x) {
    long xx = (long) x;
    if(lifo.size() == 0){
        lifo.push(xx);
        minn = xx;
        return;
    }
    if(xx <= minn){
        lifo.push(2*xx - minn);
        minn = xx;
    }
    else
        lifo.push(xx);
    
}

void pop() {
    long tp = lifo.top();
    if(tp <= minn){
        minn = 2*minn - tp;
    }
    lifo.pop();
   
}

int top() {
    long tp = lifo.top();
    if(tp <= minn){
        return (int)minn;
    }
    return (int)tp;
}

int getMin() {
    return (int)minn;
}
};
