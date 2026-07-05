class Solution {
public:
    unordered_map<int, int> mp;

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,
                    int start, int end, int &idx) {

        // Base case
        if (start > end)
            return NULL;

        // Current root from preorder
        int rootVal = preorder[idx];
        TreeNode* root = new TreeNode(rootVal);

        // Find root in inorder
        int pos = mp[rootVal];

        // Move to next preorder element
        idx++;

        // Build left subtree
        root->left = solve(preorder, inorder, start, pos - 1, idx);

        // Build right subtree
        root->right = solve(preorder, inorder, pos + 1, end, idx);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        // Store inorder indices
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        int idx = 0;

        return solve(preorder, inorder, 0, inorder.size() - 1, idx);
    }
};