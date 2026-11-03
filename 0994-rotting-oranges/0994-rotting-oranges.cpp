class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int fresh = 0, time = 0;
        queue<pair<int, int>> q;

        // Step 1: Find all Rotten Oranges .. 
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2)
                    q.push({i, j});
                else if(grid[i][j] == 1)
                    fresh++;
            }
        }

        // Step 2: Four Possible Directions 
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0 , -1};

        // Step 3: Multi-Source BFS
        while(!q.empty() && fresh > 0){
            int size = q.size();
            for(int i = 0; i < size; i++){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                for(int k = 0; k < 4; k++){
                    int newRow = row + delRow[k];
                    int newCol = col + delCol[k];
                    if(newRow >= 0 && newRow < n &&
                    newCol >= 0 && newCol < m &&
                    grid[newRow][newCol] == 1){
                        grid[newRow][newCol] = 2;
                        fresh--;
                        q.push({newRow, newCol});
                    }
                }
            }
            time++;
        }

        // Step 4: Check remaining fresh Oranges 
        if(fresh > 0)
            return -1;
        return time;
    }
};

// Complexity
// - Time: O(N × M) — every cell is processed at most once.
// - Auxiliary Space: O(N × M) — queue can hold up to N × M coordinates.