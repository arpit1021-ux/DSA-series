class Solution {
public:
    int result;
    pair<int,int>solve(TreeNode* root){
        if(!root) return {0,0};
        pair<int,int>p1=solve(root->left);
        pair<int,int>p2=solve(root->right);
        int totalsum=p1.first+p2.first+root->val;
        int totalcount=p1.second+p2.second+1;
        int avg=totalsum/totalcount;
        if(avg==root->val){
            result++;
        }
        return {totalsum,totalcount};
    }
    int averageOfSubtree(TreeNode* root) {
        result=0;
        solve(root);
        return result;
    }
};