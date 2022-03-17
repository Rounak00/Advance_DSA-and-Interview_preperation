/*
class Solution {
public:
    void solve(TreeNode *root, vector<int> &r){
       if(root==NULL){return ;}
        solve(root->left,r);
        solve(root->right,r);
        r.push_back(root->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>r;
        solve(root,r);
        return r;
    }
};
*/

//2 stack
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*>st1,st2;
        vector<int>ans;
        if(root==NULL){return ans;}
        st1.push(root);
        while(!st1.empty()){
           root=st1.top();
            st1.pop();
            st2.push(root);
            if(root->left){st1.push(root->left);}
            if(root->right){st1.push(root->right);}
        }
        
        while(!st2.empty()){
            root=st2.top();
            st2.pop();
            ans.push_back(root->val);
            
        }
        return ans;
    }
};

//1stack
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
    vector<int>ans;
    if(root==NULL){return ans;}
        stack<TreeNode*> s;
        TreeNode* cur=root;
        while(!s.empty() || cur!=NULL ){
            if(cur!=NULL){
                s.push(cur);
                cur=cur->left;
            }else{
               TreeNode* temp=s.top()->right;
                if(temp==NULL){
                   temp=s.top();
                    s.pop();
                    ans.push_back(temp->val);
                    while(!s.empty() && temp==s.top()->right){
                        temp=s.top();
                        s.pop();
                        ans.push_back(temp->val);
                    }
                }else{
                    cur=temp;
                }
            }
        }
     
        return ans;
    }
};