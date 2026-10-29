class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // Transpose the matrix 
        int n = matrix.size();
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // reverse the matrix
        for(int i = 0; i < n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

// Complexity
// - Time: (O(n^2)) — we process the (n times n) matrix.
// - Auxiliary space: (O(1)) — we modify the matrix in place without creating another matrix.