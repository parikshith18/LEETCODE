class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> visited(n, 0);
        queue<int> q;
        visited[0] = 1;
        q.push(0);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto neighbour: rooms[node]){
                if(!visited[neighbour]){
                    visited[neighbour] = 1;
                    q.push(neighbour);
                }
            }
        }

        // Check if all Rooms are visited .. 
            for(int i = 0; i < n; i++){
                if(!visited[i])
                    return false;
            }
        return true;
    }
};

// Complexity
// - Time: O(N + K), where K is the total number of keys.
// - Space: O(N), where N is total no of rooms.