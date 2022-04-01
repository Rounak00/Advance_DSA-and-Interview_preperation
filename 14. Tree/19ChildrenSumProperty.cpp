void sol(Node* root){
    if(!root){return ;}
    int ch=0;
    if(root->right){ch+=root->right->val;}
    if(root->left){ch+=root->left->val;}

    if(ch>=root->data){root->val=ch;}
    else{
        if(root->right){root->right->val=root->val;}
        if(root->left){root->left->val=root->left;}
    }

    sol(root->left);
    sol(root->right);

    int tat=0;
    if(root->right){tat+=root->right->val;}
    if(root->left){tat+=root->left->val;}

    if(root->right || root->left){root->data=tat;}
}