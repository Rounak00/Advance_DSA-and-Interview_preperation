class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* successor = NULL;
        
        while (root != NULL) {
            
            if (p->val >= root->val) {
                root = root->right;
            } else {
                successor = root;
                root = root->left;
            }
        }
        
        return successor;
    }
};

//Predescessor
Node* inOrderPredecessor(Node* root, Node* p){
	Node* predecessor = NULL;
	while(root){
		if(p->val>= root->val){
			predecessor = root;
			root = root->right;
		}
		else
			root = root->left;
	}
	return predecessor;
}