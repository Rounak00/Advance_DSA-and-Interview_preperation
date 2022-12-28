/*
Rules:-
switch(num){
    case 1: pre pey push, num++ and push to stack, left add
    case 2: in pey push, num++ and push to stack, right add
    case 3: post pey push
}
*/
Vector<int> preinpost traversal(Node* root){
    stack<pair<Node*,int>>s;
    s.push({root,1});
    vector<int>pre,post,in;
    if(root==NULL){return;}
    while(!s.empty()){
       auto it=s.top();
       s.pop();

       if(it.second==1){
           pre.push_back(it.first->val);
           it.second++;
           s.push(it);

           if(it.first->left!=NULL){
               s.push({it.first->left,1});
           }
       }

       else if(it.second==2){
           in.push_back(it.first->val);
           it.second++;
           s.push(it);
           if(it.first->right!=NULL){
               s.push({it.first->right,1});
           }
       }

       else{
           post.push_back(it.first->val);
       }
    }
}