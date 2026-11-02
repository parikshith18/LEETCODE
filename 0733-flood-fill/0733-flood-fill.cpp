class Solution {
public:
    void bfs(int row, int col, vector<vector<int>>& image,
    int initialColor, int newColor){
        int n = image.size(), m = image[0].size();
        queue<pair<int, int>> q;
        q.push({row, col});
        image[row][col] = newColor;

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
                image[newRow][newCol] == initialColor){
                    image[newRow][newCol] = newColor;
                    q.push({newRow, newCol});
                }
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor = image[sr][sc];
        if(initialColor == color)
            return image;

        bfs(sr, sc, image, initialColor, color);
        return image;
    }
};

// Complexity: O(N × M) time, O(N × M) auxiliary space in the worst case.