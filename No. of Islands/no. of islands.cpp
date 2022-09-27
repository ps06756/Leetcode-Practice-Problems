class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        
        for(int row = 0; row < grid.size(); row++) {
            for(int col = 0; col < grid[0].size(); col++) {
                if (grid[row][col] == '1') {
                    count++;
                    dfs(row, col, grid);
                }
            }
        }
        return count;
    }
    
    
    void dfs(int row, int col, vector<vector<char>>& grid) {
        if (isValid(row, col, grid)) {
            grid[row][col] = '2';
            dfs(row - 1, col, grid);
            dfs(row + 1, col, grid);
            dfs(row, col - 1, grid);
            dfs(row, col + 1, grid);
        }    
    }
    
    bool isValid(int row, int col, vector<vector<char>>& grid) {
        if (row < 0 || row >= grid.size()) return false;
        if (col < 0 || col >= grid[0].size()) return false; 
        
        if (grid[row][col] == '1') return true;
        return false;
    }
};