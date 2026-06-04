class Solution {
public:
    struct pairHash {
        size_t operator()(const pair<int, int>& p) const {
            return hash<int>()(p.first) ^
                   (hash<int>()(p.second) << 1);
        }
    };

    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> rows, cols;
        unordered_map<pair<int, int>, unordered_set<char>, pairHash> squares;

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') continue;

                pair<int, int> squareKey = {r / 3, c / 3};

                if (rows[r].count(board[r][c]) ||
                    cols[c].count(board[r][c]) ||
                    squares[squareKey].count(board[r][c])) {
                    return false;
                }

                rows[r].insert(board[r][c]);
                cols[c].insert(board[r][c]);
                squares[squareKey].insert(board[r][c]);
            }
        }
        return true;
    }
};