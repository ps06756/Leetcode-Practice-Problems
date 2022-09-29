class Solution {
    public int numEnclaves(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        
        for(int i = 0; i < m; i++) {
            dfsCore(i, 0, grid);
            dfsCore(i, n - 1, grid);
        }
        
        for(int i = 0; i < n; i++) {
            dfsCore(0, i, grid);
            dfsCore(m - 1, i, grid);
        }
        
        int count = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    count++;
                }
            }
        }
        
        return count;
    }
    
    public void dfsCore(int row, int col, int[][] grid) {
        if (row >= 0 && row < grid.length && col >=0 && col < grid[0].length &&
           grid[row][col] == 1) {
            grid[row][col] = 0;
            dfsCore(row - 1, col, grid);
            dfsCore(row + 1, col, grid);
            dfsCore(row, col - 1, grid);
            dfsCore(row, col + 1, grid);
        }
    }
}