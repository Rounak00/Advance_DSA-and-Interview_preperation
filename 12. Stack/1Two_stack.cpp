//Naive: divide the space:
/*

struct TwoStacks { 
    int* arr; 
    int cap; 
    int top1, top2; 
    
    TwoStacks(int n) 
    { 
        cap = n; 
        arr = new int[n]; 
        top1 = n / 2 + 1; 
        top2 = n / 2; 
    } 
  
    void push1(int x) 
    { 
        
        if (top1 > 0) { 
            top1--; 
            arr[top1] = x; 
        } 
        else { 
            cout << "Stack Overflow"
                 << " By element :" << x << endl; 
            return; 
        } 
    } 
  
    void push2(int x) 
    { 
        if (top2 < cap - 1) { 
            top2++; 
            arr[top2] = x; 
        } 
        else { 
            cout << "Stack Overflow"
                 << " By element :" << x << endl; 
            return; 
        } 
    } 
   
    int pop1() 
    { 
        if (top1 <= cap / 2) { 
            int x = arr[top1]; 
            top1++; 
            return x; 
        } 
        else { 
            cout << "Stack UnderFlow"; 
            exit(1); 
        } 
    } 
   
    int pop2() 
    { 
        if (top2 >= cap / 2 + 1) { 
            int x = arr[top2]; 
            top2--; 
            return x; 
        } 
        else { 
            cout << "Stack UnderFlow"; 
            exit(1); 
        } 
    } 
}; 

*/

//Efficient: Start from two sides:

#include <bits/stdc++.h>
using namespace std;

struct TwoStacks { 
    int* arr; 
    int cap; 
    int top1, top2; 
    
    TwoStacks(int n)  
    { 
        cap = n; 
        arr = new int[n]; 
        top1 = -1; 
        top2 = cap; 
    } 
  
    void push1(int x) 
    { 
        if (top1 < top2 - 1) { 
            top1++; 
            arr[top1] = x; 
        } 
        else { 
            cout << "Stack Overflow"; 
            exit(1); 
        } 
    } 
  
    void push2(int x) 
    { 
        if (top1 < top2 - 1) { 
            top2--; 
            arr[top2] = x; 
        } 
        else { 
            cout << "Stack Overflow"; 
            exit(1); 
        } 
    } 
  
    int pop1() 
    { 
        if (top1 >= 0) { 
            int x = arr[top1]; 
            top1--; 
            return x; 
        } 
        else { 
            cout << "Stack UnderFlow"; 
            exit(1); 
        } 
    } 
  
    int pop2() 
    { 
        if (top2 < cap) { 
            int x = arr[top2]; 
            top2++; 
            return x; 
        } 
        else { 
            cout << "Stack UnderFlow"; 
            exit(1); 
        } 
    } 
};
  
int main() 
{ 
    TwoStacks ts(5); 
    ts.push1(5); 
    ts.push2(10); 
    ts.push2(15); 
    ts.push1(11); 
    ts.push2(7); 
    cout << "Popped element from stack1 is "<<ts.pop1(); 
    ts.push2(40); 
    cout << "\nPopped element from stack2 is "<< ts.pop2(); 
    return 0; 
}
