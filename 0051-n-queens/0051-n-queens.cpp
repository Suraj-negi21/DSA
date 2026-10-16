class Solution {
public:
    vector<vector<string>> ans;

    bool can_place(int r, int c, vector<string>& board, int n) {

        int i = r;
        int j = c;

        while (i >= 0) {
            if (board[i][j] == 'Q') {
                return false;
            }
            i--;
        }

        i = r;
        j = c;

        while (i >= 0 && j >= 0) {
            if (board[i][j] == 'Q') {
                return false;
            }
            i--;
            j--;
        }

        i = r;
        j = c;

        while (i >= 0 && j < n) {
            if (board[i][j] == 'Q') {
                return false;
            }
            i--;
            j++;
        }

        return true;
    }

    void f(int r, int n, vector<string>& board) {

        if (r == n) {
            ans.push_back(board);
            return;
        }

        for (int j = 0; j < n; j++) {

            if (can_place(r, j, board, n)) {

                board[r][j] = 'Q';

                f(r + 1, n, board);

                board[r][j] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<string> board(n, string(n, '.'));

        f(0, n, board);

        return ans;
    }
};