class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        // Step 1: Check Start and Destination..
        if(grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;

        // Step 2: Queue
        queue<pair<pair<int, int>, int>> q;
        q.push({{0, 0}, 1});
        grid[0][0] = 1;

        // Step 3 : Eight Directions.. 
        int delRow[] = {-1,-1,-1,0,0,1,1,1};
        int delCol[] = {-1,0,1,-1,1,-1,0,1};

        // Step 4: BFS
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int distance = q.front().second;
            q.pop();

            if(row == n - 1 && col == n - 1)
                return distance;

            for(int k = 0; k < 8; k++){
                int newRow = row + delRow[k];
                int newCol = col + delCol[k];

                if(newRow >= 0 && newRow < n &&
                   newCol >= 0 && newCol < n &&
                   grid[newRow][newCol] == 0) {
                        grid[newRow][newCol] = 1;
                        q.push({{newRow,newCol}, distance + 1});
                }

            }
        }
        return -1;
    }
};

// 4. Complexity
// Complexity	Explanation
// Time	O(N²)
// Auxiliary Space	O(N²)