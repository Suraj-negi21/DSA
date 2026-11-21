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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        vector<int>ans;
        if(root == NULL) return ans;
        while(!q.empty()){
            
            auto size=q.size();
           
            for(int i=0;i<size;i++){
             auto cur=q.front();
             q.pop();
             if(i==size-1){
                ans.push_back(cur->val);

             }
             if(cur->left!=NULL)q.push(cur->left);
            if(cur->right!=NULL)q.push(cur->right);

            }

        }
        return ans;
    }
};