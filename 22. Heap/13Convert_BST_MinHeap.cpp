void preorder(node *root, vector<int>vec){
    if(!root){return;}
    root->val=vec.front();
    vec.erase(a.begin());
    preorder(root->left,vec);
    preorder(root->right,vec);
}

node solution(node *root){
 vector<int>vec;
 inorder(root, vec); //basically store all nodes in sorted bcz inorder of BST is sorted
 preorder(root, vec);
 return  root;
}