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
    int count = 0;
    int helper(TreeNode *root){
        if(root == NULL){
            return 2;
        }

        int l = helper(root->left);
        int r = helper(root->right);
        if(l == 0 || r == 0){
            count++;
            return 1;
        }else if(l == 1 || r == 1){
            return 2;
        }

        return 0;

    }
    int minCameraCover(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        if(root->left == NULL && root->right == NULL){
            return 1;
        }
        if(helper(root) == 0){
            count++;
        }
        return count;
    }
};