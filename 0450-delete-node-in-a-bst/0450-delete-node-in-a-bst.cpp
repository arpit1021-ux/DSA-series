class Solution {
public:

    // Find the leftmost node (minimum) in a subtree
    TreeNode* findMin(TreeNode* root) {
        while (root->left != nullptr) {
            root = root->left;
        }
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {

        // Base Case
        if (root == nullptr)
            return nullptr;

        // Search in left subtree
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }

        // Search in right subtree
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }

        // Node found
        else {

            // Case 1 : Leaf Node
            if (root->left == nullptr && root->right == nullptr) {
                delete root;
                return nullptr;
            }

            // Case 2 : Only Right Child
            else if (root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            // Case 3 : Only Left Child
            else if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Case 4 : Two Children
            else {

                // Find inorder successor
                TreeNode* successor = findMin(root->right);

                // Copy successor value
                root->val = successor->val;

                // Delete duplicate successor node
                root->right = deleteNode(root->right, successor->val);
            }
        }

        // Return updated subtree root
        return root;
    }
};