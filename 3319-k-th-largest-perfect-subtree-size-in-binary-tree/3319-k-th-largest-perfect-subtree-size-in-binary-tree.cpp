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
    vector<int> res;
    pair<int,int> dfs(TreeNode* root){
        if(root == NULL){
            return {true,0};
        }

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        if(left.first && right.first && left.second == right.second){
            res.push_back(left.second+right.second+1);
            return {true,left.second+right.second+1};
        }
        return {false,0};
    }
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        if(root == NULL){
            return 0;
        }
        
        dfs(root);
        
        sort(res.rbegin(),res.rend());
        if(res.size() >= k){
            return res[k-1];
        }
        return -1;

    }
};