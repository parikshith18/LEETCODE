class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set <string> st;
        for(auto& path: paths)
            st.insert(path[0]);

        for(auto& path: paths){
            if(!st.count(path[1]))
                return path[1];
        } 
        return "";
    }
};

// Time: (O(n)) average — one pass to build the set, another to check destinations.
// Space: (O(n)) — the set stores the starting cities.

// BRUTE FORCE 
// class Solution {
// public:
//     string destCity(vector<vector<string>>& paths) {
//         int n = paths.size();
//         for(int i = 0; i < n; i++){
//             bool found = false;
//             string destination = paths[i][1];
//             for(int j = 0; j < n; j++){
//                 if(destination == paths[j][0]){
//                     found = true; 
//                     break;
//                 }
//             }

//             if(!found){
//                 return destination;
//             }
//         }
//         return "";
//     }
// };

// Complexity
// - Time: (O(n^2)), because of nested loops.
// - Space: (O(1)) auxiliary space.