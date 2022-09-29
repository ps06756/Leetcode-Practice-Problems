class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> distance(m);
        for(int i = 0; i < m; i++) {
            distance[i] = vector<int>(n, 0);
        }
        
        queue<pair<int, int>> que;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    distance[i][j] = m*n;
                }
                else {
                    distance[i][j] = 0;
                    que.push(make_pair(i, j));
                }
            }
        }
        
        while (que.size() > 0) {
            pair<int,int> top = que.front();
            que.pop();
            int row = top.first, col = top.second;
            
            int newDistance = distance[row][col] + 1;
            if (isValid(row - 1, col, mat) && distance[row-1][col] > newDistance) {
                distance[row-1][col] = newDistance;
                que.push(make_pair(row - 1, col));
            }
            if (isValid(row + 1, col, mat) && distance[row + 1][col] > newDistance) {
                distance[row + 1][col] = newDistance;
                que.push(make_pair(row + 1, col));
            }
            if (isValid(row, col - 1, mat) && distance[row][col - 1] > newDistance) {
                distance[row][col - 1] = newDistance;
                que.push(make_pair(row, col - 1));
            }
            if (isValid(row, col + 1, mat) && distance[row][col + 1] > newDistance) {
                distance[row][col + 1] = newDistance;
                que.push(make_pair(row, col + 1));
            }
        }
        return distance;
    }
    
    bool isValid(int row, int col, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        if (row < 0 || row >= m) return false;
        if (col < 0 || col >= n) return false;
        if (mat[row][col] != 1) return false;
        return true;
    }
};