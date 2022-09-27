class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'P';
                }
            }
        }
        
        for(int j = 0; j < n; j++) {
            dfsCore(0, j, board);
            dfsCore(m - 1, j, board);
        }
        
        for(int i = 0; i < m; i++) {
            dfsCore(i, 0, board);
            dfsCore(i, n - 1, board);
        }
        
         for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if (board[i][j] == 'P') {
                    board[i][j] = 'X';
                }
            }
        }
        
        
    }
    
    void dfsCore(int row, int col, vector<vector<char>>& board) {
        if (row >= 0 && row < board.size() && col >= 0 && col < board[0].size() && board[row][col] == 'P') {
            board[row][col] = 'O';
            dfsCore(row - 1, col, board);
            dfsCore(row + 1, col, board);
            dfsCore(row, col - 1, board);
            dfsCore(row, col + 1, board);
        }
    }
};