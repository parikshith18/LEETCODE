class Solution {
public:
    void bfs(int row, int col, vector<vector<char>>& grid){
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({row, col});
        grid[row][col] = '0';

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int k = 0; k < 4; k++){
                int newRow = row + delRow[k];
                int newCol = col + delCol[k];

                if(newRow >= 0 && newRow < n &&
                newCol >= 0 && newCol < m &&
                grid[newRow][newCol] == '1'){
                    grid[newRow][newCol] = '0';
                    q.push({newRow, newCol});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int island = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1'){
                    island++;
                    bfs(i, j, grid);
                }
            }
        }
        return island;
    }
};

// Complexity for LC 200:
// - Time: O(N × M)
// - Auxiliary space: O(N × M) worst case (queue).