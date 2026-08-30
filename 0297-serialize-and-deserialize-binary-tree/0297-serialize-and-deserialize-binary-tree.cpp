/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        if(root == NULL){
            return s;
        }
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            auto x = q.front();
            q.pop();

            if(x == NULL){
                s += "#,";
            }else{
                s += to_string(x->val) + ",";

                q.push(x->left);

                q.push(x->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()){
            return NULL;
        }

        stringstream s(data);
        string str;

        getline(s,str,',');

        TreeNode* node = new TreeNode(stoi(str));
        queue<TreeNode*> q;

        q.push(node);

        while(!q.empty()){
            auto x  = q.front();
            q.pop();

            getline(s,str,',');

            if(str != "#"){
                TreeNode *leftnode = new TreeNode(stoi(str));
                x->left = leftnode;
                q.push(leftnode);
            }

            getline(s,str,',');

            if(str != "#"){
                TreeNode *rightnode = new TreeNode(stoi(str));
                x->right = rightnode;
                q.push(rightnode);
            }
        }

        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));