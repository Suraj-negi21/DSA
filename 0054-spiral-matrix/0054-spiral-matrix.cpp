class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int> ans;

        int n = matrix.size();
        int m = matrix[0].size();

        int sw = 0;
        int st = 0;
        int ew = n - 1;
        int en = m - 1;

        while (st <= en && sw <= ew) {

            // Top row
            for (int j = st; j <= en; j++) {
                ans.push_back(matrix[sw][j]);
            }
            sw++;

            // Right column
            for (int i = sw; i <= ew; i++) {
                ans.push_back(matrix[i][en]);
            }
            en--;

            // Bottom row
            if (sw <= ew) {
                for (int j = en; j >= st; j--) {
                    ans.push_back(matrix[ew][j]);
                }
                ew--;
            }

            // Left column
            if (st <= en) {
                for (int i = ew; i >= sw; i--) {
                    ans.push_back(matrix[i][st]);
                }
                st++;
            }
        }

        return ans;
    }
};