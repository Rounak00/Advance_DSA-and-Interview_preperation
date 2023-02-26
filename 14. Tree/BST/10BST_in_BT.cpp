//Brute Force : 7a use for each node and check every nodes max size
//TC: O(N)*O(N)

// Optimize
class Node{
    public:
      int maxNode,minNode,maxSize;

      Node(int minVal,int maxVal, int siz){
        minNode=minVal;
        maxNode=maxVal;
        maxSize=siz;
      }
};

class Solution {
 public:
    int largestBSTSubtree(TreeNode* root) {
        return largestBSTSubtreeHelper(root).maxSize;
    }

    Node largestBSTSubtreeHelper(TreeNode* root) {
        // An empty tree is a BST of size 0.
        if (!root) {
            return Node(1e9, -1e9, 0);
        }
        
        // Get values from left and right subtree of current tree.
        auto left = largestBSTSubtreeHelper(root->left);
        auto right = largestBSTSubtreeHelper(root->right);
        
        // Current node is greater than max in left AND smaller than min in right, it is a BST.
        if (left.maxNode < root->val && root->val < right.minNode) {
            // It is a BST.
            return Node( min(root->val, left.minNode), max(root->val, right.maxNode), 
                            left.maxSize + right.maxSize + 1);
        }
        
        // Otherwise, return [-inf, inf] so that parent can't be valid BST
        return Node(-1e9, 1e9, max(left.maxSize, right.maxSize));
    }
    
    
};

class Solution {
private:
    NodeValue largestBSTSubtreeHelper(TreeNode* root) {
        // An empty tree is a BST of size 0.
        if (!root) {
            return NodeValue(INT_MAX, INT_MIN, 0);
        }
        
        // Get values from left and right subtree of current tree.
        auto left = largestBSTSubtreeHelper(root->left);
        auto right = largestBSTSubtreeHelper(root->right);
        
        // Current node is greater than max in left AND smaller than min in right, it is a BST.
        if (left.maxNode < root->val && root->val < right.minNode) {
            // It is a BST.
            return NodeValue(min(root->val, left.minNode), max(root->val, right.maxNode), 
                            left.maxSize + right.maxSize + 1);
        }
        
        // Otherwise, return [-inf, inf] so that parent can't be valid BST
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }
    public:
    int largestBSTSubtree(TreeNode* root) {
        return largestBSTSubtreeHelper(root).maxSize;
    }
};