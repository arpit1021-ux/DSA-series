class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>post;
        stack<TreeNode*>st1;
        stack<TreeNode*>st2;
        st1.push(root);
        if(root==NULL) return post;
        while(!st1.empty()){
            TreeNode* node=st1.top(); st1.pop();
            st2.push(node);
            if(node->left) st1.push(node->left);
            if(node->right) st1.push(node->right);
        }
        while(!st2.empty()){
            post.push_back(st2.top()->val);
            st2.pop();
        }
        return post;
    }
};