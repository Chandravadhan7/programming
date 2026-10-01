/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> arr;
    void inorder(TreeNode* root){
        if(root == NULL){
            return;
        }
        inorder(root->left);
        arr.push_back(root->val);
        inorder(root->right);
    }
    TreeNode* construct(int l,int r){
        if(r < l){
            return NULL;
        }

        int mid = l + (r-l)/2;

        TreeNode* root = new TreeNode(arr[mid]);

        root->left = construct(l,mid-1);
        root->right = construct(mid+1,r);

        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        int n = arr.size();
        return construct(0,n-1);
    }
};