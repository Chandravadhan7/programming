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
    pair<int,int> helper(TreeNode* root){
        if(root == NULL){
            return {0,0};
        }

        pair<int,int> left = helper(root->left);
        pair<int,int> right = helper(root->right);

        if(root->val == (left.second+right.second+root->val)/(left.first+right.first+1)){
            count++;
        }

        return {1+left.first+right.first,root->val+left.second+right.second};
    }
    int averageOfSubtree(TreeNode* root) {
        helper(root);

        return count;
    }
};