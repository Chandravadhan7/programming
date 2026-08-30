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
    int maax = INT_MIN;
    int sum(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int leftsum = max(0,sum(root->left));
        int rightsum = max(0,sum(root->right));

        maax = max(maax,root->val+leftsum+rightsum);

        return root->val + max(leftsum,rightsum);
    }
    int maxPathSum(TreeNode* root) {
        sum(root);
        return maax;
    }
};