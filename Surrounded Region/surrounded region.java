class Solution {
    public void solve(char[][] board) {
        int m = board.length;
        int n = board[0].length;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'P';
                }
            }
        }
        
        for(int j = 0; j < n; j++) {
            dfsCore(0, j, board);
        }
        for(int j = 0; j < n; j++) {
            dfsCore(m - 1, j, board);
        }
        for(int i = 0; i < m; i++) {
            dfsCore(i, 0, board);
        }
        for(int i = 0; i < m; i++) {
            dfsCore(i, n - 1, board);
        }
        
        for(int i = 0 ; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if (board[i][j] == 'P') { 
                    board[i][j] = 'X';
                }
            }
        }
    }
    
    public void dfsCore(int row, int col, char[][] board) {
        if (row >= 0 && row < board.length && col >= 0 && col < board[0].length && board[row][col] == 'P') {
            board[row][col] = 'O';
            dfsCore(row - 1, col, board);
            dfsCore(row + 1, col, board);
            dfsCore(row, col - 1, board);
            dfsCore(row, col + 1, board);
        }
    }
}