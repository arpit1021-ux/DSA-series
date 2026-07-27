class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return "";
        string ans="";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node==NULL){
                ans+="#,";
            }
            else{
                ans+=to_string(node->val)+",";
                q.push(node->left);
                q.push(node->right);
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

    if(data.size()==0)
        return NULL;

    stringstream ss(data);// to get one token at a time it is used to parse data from string 

    string str;

    getline(ss,str,',');// every call returns one token 

    TreeNode* root=new TreeNode(stoi(str));

    queue<TreeNode*> q;

    q.push(root);

    while(!q.empty()){

        TreeNode* node=q.front();
        q.pop();

        getline(ss,str,',');

        if(str!="#"){

            TreeNode* leftNode=new TreeNode(stoi(str));

            node->left=leftNode;

            q.push(leftNode);
        }

        getline(ss,str,',');

        if(str!="#"){

            TreeNode* rightNode=new TreeNode(stoi(str));

            node->right=rightNode;

            q.push(rightNode);
        }
    }

    return root;
}
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));