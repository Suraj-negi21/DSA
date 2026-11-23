class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        unordered_map<int, vector<pair<int, int>>> mp;
        queue<tuple<TreeNode*, int, int>> q;

        q.push({root, 0, 0});

        int start = INT_MAX;
        int end = INT_MIN;

        while (!q.empty()) {

            auto [node, col, row] = q.front();
            q.pop();

            start = min(start, col);
            end = max(end, col);

            mp[col].push_back({row, node->val});

            if (node->left) {
                q.push({node->left, col - 1, row + 1});
            }

            if (node->right) {
                q.push({node->right, col + 1, row + 1});
            }
        }

        vector<vector<int>> ans;

        for (int col = start; col <= end; col++) {

            sort(mp[col].begin(), mp[col].end());

            vector<int> values;

            for (auto p : mp[col]) {
                values.push_back(p.second);
            }

            ans.push_back(values);
        }

        return ans;
    }
};