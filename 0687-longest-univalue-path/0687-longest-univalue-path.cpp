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
    int maax = 0;
    int path(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int left = path(root->left);
        int right = path(root->right);

        int l = 0;

        if(root->left && root->left->val == root->val){
           l = left + 1;
        }
        int r = 0;
        if(root->right && root->right->val == root->val){
            r = right + 1;
        }

        maax = max(maax,l+r);

        return max(l,r);
        
        maax = max(maax,left+right);

        return left+right;
    }
    int longestUnivaluePath(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        
        path(root);
        
        return maax;
    }
};