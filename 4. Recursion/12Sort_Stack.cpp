

void pos(stack<int>a,int tem){
    if(a.size()==0){
        a.push(tem);
    }
    
    if((a.top())<tem){
        a.push(tem);
    }
    else{
        int temp=a.top();
        a.pop();
        pos(a,tem);
        a.push(temp);
    }
}

void sorty(stack<int>a){
   if(a.size()==1){
       return;
   }
   int temp=a.top();
   a.pop();
   sorty(temp);
   pos(a,temp);
    
}




int main() {
    
    stack<int>a;
    a.push(3);
    a.push(1);
    a.push(2);
    a.push(0);
    sorty(a);
    while(!a.empty()){
        cout<<a.top()<<" ";
        a.pop();
    }
    return 0;
}