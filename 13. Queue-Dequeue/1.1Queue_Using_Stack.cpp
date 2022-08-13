/*
naive using two stack and every time simply put another stack then push then take all elements from that stack
*/

//Most Efficient TC: o(1)

class Solution{
    public:

    stack<int>in,out;


    void transfer(stack<int>&in,stack<int>&out) {
        while(in.size()>0){
            out.push(in.top());
            in.pop();
        }
    } 
    void push(int val){
      in.push(val);
    }

    void pop(){
        if(out.size()==0){
            transfer(in,out);
            return out.top();
        }
        return out.top();
    }

    int top(){
        if(out.size()==0){
            transfer(in,out);
            return out.top();
        }
        return out.top();
    }
}