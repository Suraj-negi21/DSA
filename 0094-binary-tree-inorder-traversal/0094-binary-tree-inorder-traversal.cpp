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
    vector<int>ans;
    void helper(TreeNode* r){
        if(r==NULL)return;
        inorderTraversal(r->left);
        ans.push_back(r->val);
        inorderTraversal(r->right);


    }
    vector<int> inorderTraversal(TreeNode* root) {
        helper(root);
        return ans;
    }
};