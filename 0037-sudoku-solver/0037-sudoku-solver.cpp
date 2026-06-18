class Solution {
public:
    bool solve(vector<vector<char>>& board, vector<int>& row, vector<int>& col, vector<int>& box) {
        int r = -1, c = -1;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    r = i;
                    c = j;
                    goto found;
                }
            }
        }

        return true;

        found:

        int b = (r / 3) * 3 + (c / 3);

        for (int d = 1; d <= 9; d++) {
            int mask = 1 << d;

            if ((row[r] & mask) || (col[c] & mask) || (box[b] & mask))
                continue;

            board[r][c] = d + '0';
            row[r] |= mask;
            col[c] |= mask;
            box[b] |= mask;

            if (solve(board, row, col, box))
                return true;

            board[r][c] = '.';
            row[r] ^= mask;
            col[c] ^= mask;
            box[b] ^= mask;
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        vector<int> row(9, 0), col(9, 0), box(9, 0);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int d = board[i][j] - '0';
                    int mask = 1 << d;
                    row[i] |= mask;
                    col[j] |= mask;
                    box[(i / 3) * 3 + (j / 3)] |= mask;
                }
            }
        }

        solve(board, row, col, box);
    }
};