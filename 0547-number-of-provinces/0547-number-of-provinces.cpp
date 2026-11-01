class Solution {
public:
    // JOB B : BFS to visit all connectedn cities
    void bfs(int i, vector<vector<int>>& isConnected, vector<int>& visited){
        int n = isConnected.size();
        queue<int> q;
        visited[i] = 1;
        q.push(i);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int neighbour = 0; neighbour < n; neighbour++){
                if(isConnected[node][neighbour] == 1 &&
                !visited[neighbour]){
                    visited[neighbour] = 1;
                    q.push(neighbour);
                }
            }
        }
    }

    // JOB A: COUNT NO OF PROVINCE
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), provinces = 0;
        vector<int> visited(n, 0);
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                provinces++;
                bfs(i, isConnected, visited);
            }
        }
        return provinces;
    }
};

// Complexity
// - Time: O(N²)
// - Space: O(N)