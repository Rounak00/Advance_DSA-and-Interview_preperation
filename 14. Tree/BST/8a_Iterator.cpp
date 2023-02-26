class BSTIterator {
    stack<TreeNode *> myStack;
public:
    BSTIterator(TreeNode *root) {
        pushAll(root);
    }

    /** return whether we have a next smallest number */
    bool hasNext() {
        return !myStack.empty();
    }

    /** return the next smallest number */
    int next() {
        TreeNode *tmpNode = myStack.top();
        myStack.pop();
        pushAll(tmpNode->right);
        return tmpNode->val;
    }

private:
    void pushAll(TreeNode *node) {
        for (; node != NULL; myStack.push(node), node = node->left);
    }
};



//Before function as H/W
 int before(){
    TreeNode* t=myStack.top();
    myStack.pop();
    pushallR(t->left);
    return t->val; 
 }

 void pushallR(TreeNode *root){
    for(;root!=NULL; myStack.push(root), root=root->right);
 }


 //BST Iterator
 class BSTIterator {
    stack<TreeNode *> myStack;
    bool reverse = true; //treu means before() and false means next();
public:
    BSTIterator(TreeNode *root, bool isReverse) {
        reverse = isReverse; 
        pushAll(root);
    }

    /** return whether we have a next smallest number */
    bool hasNext() {
        return !myStack.empty();
    }

    /** return the next smallest number */
    int next() {
        TreeNode *tmpNode = myStack.top();
        myStack.pop();
        if(!reverse) pushAll(tmpNode->right);
        else pushAll(tmpNode->left);
        return tmpNode->val;
    }

private:
    void pushAll(TreeNode *node) {
        for(;node != NULL; ) {
             myStack.push(node);
             if(reverse == true) {
                 node = node->right; 
             } else {
                 node = node->left; 
             }
        }
    }
};