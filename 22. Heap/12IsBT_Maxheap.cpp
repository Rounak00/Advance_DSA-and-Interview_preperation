bool order(root){
    if(!root || (root->right==NULL && root->left==NULL)){return true;}
    if(!root->right){
        return root->left->val<root->val;
    }
    else{
      return (root->left->val<root->val && root->right->val<root->val)&& order(root->right)&& order(root->left);  
    }
}
bool CBT(node *root,int i, int count){
    if(!root)return true;
    if(i>count){return 0;}
    else{
        return CBT(root->left,2*i+1,count)&& CBT(root->right,2*i+2,count);
    }
}

int solution(node *root){
 int count=0;
 count=countNode(root);
 if(CBT(root,0,count)&&order(root)){
     return true;
 }   
 return false;
}