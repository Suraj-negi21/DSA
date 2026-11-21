
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL)return 0;

        int ans = 0;

        if(root->left != NULL && root->left->left == NULL && root->left->right == NULL){
            ans += root->left->val;
        }

        ans += sumOfLeftLeaves(root->left);
        ans += sumOfLeftLeaves(root->right);

        return ans;
    }
};