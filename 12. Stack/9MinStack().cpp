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
#include <bits/stdc++.h>
using namespace std;

struct MyStack {
 
    stack<int> s;
    int min;
 
void push(int x) {
 
      if(s.empty() ) {
         min=x;
         s.push(x);
      }
      else if(x<=min){
          s.push(2*x-min);
          min=x;
      }else{
      s.push(x);
      }
   }
 
int pop() {

    int t=s.top();s.pop();
    if(t<=min){
        int res=min;
        min=2*min-t;
        return res;
    }else{
        return t;
    }
   }

int top() {
    int t=s.top();
    return ((t<=min)? min : t);
   }
 
int getMin() {
      return min;
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
