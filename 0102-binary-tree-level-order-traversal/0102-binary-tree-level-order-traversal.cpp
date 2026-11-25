class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if(root == NULL) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            vector<int> temp;

            for(int i = 0; i < size; i++) {
                TreeNode* cur = q.front();
                q.pop();

                temp.push_back(cur->val);

                if(cur->left != NULL) q.push(cur->left);
                if(cur->right != NULL) q.push(cur->right);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};