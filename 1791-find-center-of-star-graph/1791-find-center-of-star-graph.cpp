class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        if(edges[0][0] == edges[1][0] ||
        edges[0][0] == edges[1][1])
            return edges[0][0];
        return edges[0][1];
    }
};

// Time: O(1)
// Space: O(1)



// BRUTE FORCE
// class Solution {
// public:
//     int findCenter(vector<vector<int>>& edges) {
//         unordered_map<int, int> mp;

//         // Step 1 - count the frequency of each vertex.. 
//         for(auto edge: edges){
//             mp[edge[0]]++;
//             mp[edge[1]]++;
//         }

//         // Step 2 - find the vertex with max frequency... 
//         int center = -1, maxi = 0;
//         for(auto it: mp){
//             if(it.second > maxi){
//                 maxi = it.second;
//                 center = it.first;
//             }
//         }
//         return center;
//     }
// };

// // Complexity
// // - Time: O(E) average, where E is the number of edges.
// // - Space: O(V), where V is the number of vertices.