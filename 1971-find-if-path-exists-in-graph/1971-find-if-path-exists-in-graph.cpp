class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // if source and dest same..
        if(source == destination)
            return true;

        // Step 1: Build adjacency List..
        vector<int> adj[n];
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Step 2: Create visited array and Queue as it is BFS
        vector<int> visited(n, 0);
        queue<int> q;
        visited[source] = 1;
        q.push(source);

        // Step 3: Create BFS Traversal
        while(!q.empty()){
            int node = q.front();
            q.pop();

            if(node == destination)
                return true;

            for(int neighbour: adj[node]){
                if(!visited[neighbour]){
                    visited[neighbour] = 1;
                    q.push(neighbour);
                }
            }
        }
        return false;
    }
};

// Complexity of BFS:
// - Time: O(V + E)
// - Space: O(V)