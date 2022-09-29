class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
       
        for(int i = 0; i < grid.size(); i++) {
            dfsCore(i, 0, grid);
            dfsCore(i, grid[0].size() - 1, grid);
        }
        
        for(int j = 0; j < grid[0].size(); j++) {
            dfsCore(0, j, grid);
            dfsCore(grid.size() -1, j, grid);
        }
        
        int count = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    count++;
                }
            }
        }
        
        return count;
    }
    
    void dfsCore(int row, int col, vector<vector<int>>& grid) {
        if (row >= 0 && row < grid.size() && col >=0 && col < grid[0].size() && grid[row][col] == 1) {
            grid[row][col] = 0;
            dfsCore(row - 1, col, grid);
            dfsCore(row + 1, col, grid);
            dfsCore(row, col - 1, grid);
            dfsCore(row, col + 1, grid);
        }
    }
};