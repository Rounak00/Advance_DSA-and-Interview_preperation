///If question is kth largest then first count nodes that is N;
// secind run kth smallest function with(root, N-k);




//Inorder of a BST is always sorted
class Solution {
public:
    void inorder(TreeNode* root, vector<int> &res){
        if(!root)
            return;
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right,res);
        
    }
    int kthSmallest(TreeNode* root, int k) {
        if(!root)
            return -1;
        vector<int> arr;
        inorder(root, arr);
        return arr[k-1];

    }
};

//More optimise
class Solution {
    public int kthSmallest(TreeNode root, int k) {
        Stack<TreeNode> stack = new Stack<TreeNode>();
        TreeNode node = root;
        int cnt = 0; 
        while(true){
            if(node != null){
                stack.push(node);
                node = node.left;
            }
            else{
                if(stack.isEmpty()){
                    break;
                }
                node = stack.pop();
                // inorder.add(node.val);
                cnt++; 
                if(cnt == k) return node.val; 
                node = node.right;
            }
        }
        return -1; 
    }
}

//Using MorrisTraversal: SC= o(1) TC=o(N)

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
       int cnt=0;
        int ret;
      TreeNode* cur = root; 
        while(cur != NULL) {
            if(cur->left == NULL) {
                cnt++;
                if(cnt==k){ret=cur->val;}
                cur = cur->right; 
            }
            else {
                TreeNode* prev = cur->left; 
                while(prev->right != NULL && prev->right != cur) {
                    prev = prev->right; 
                }
                
                if(prev->right == NULL) {
                    prev->right = cur;
                    cur = cur->left; 
                }
                else {
                    prev->right = NULL; 
                    cnt++;
                    if(cnt==k){ret=cur->val;} 
                    cur = cur->right; 
                }
            }
        }
        return ret; 
    }
};