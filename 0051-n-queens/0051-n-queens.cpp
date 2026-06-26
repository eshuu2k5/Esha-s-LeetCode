class Solution {
public:
    vector<vector<string>> ans;
    vector<string> board;
    vector<int> col, d1, d2;

    void solve(int r, int n) {
        if (r == n) {
            ans.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++) {
            if (col[c] || d1[r - c + n - 1] || d2[r + c]) continue;

            board[r][c] = 'Q';
            col[c] = d1[r - c + n - 1] = d2[r + c] = 1;

            solve(r + 1, n);

            board[r][c] = '.';
            col[c] = d1[r - c + n - 1] = d2[r + c] = 0;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        board.assign(n, string(n, '.'));
        col.assign(n, 0);
        d1.assign(2 * n - 1, 0);
        d2.assign(2 * n - 1, 0);

        solve(0, n);
        return ans;
    }
};