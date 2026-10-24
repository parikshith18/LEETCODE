class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> mp;
        int count = 0;
        for(int x: nums){
            count += mp[x];
            mp[x]++;
        }
        return count;
    }
};

// Time Complexity: O(n) — one traversal of the array, with average O(1) HashMap operations.
// Space Complexity: O(n) — the map can store up to n distinct numbers.

// BRUTE FORCE
// class Solution {
// public:
//     int numIdenticalPairs(vector<int>& nums) {
//         int count = 0, n = nums.size();
//         for(int i = 0; i < n; i++){
//             for(int j = i + 1; j < n; j++){
//                 if(nums[i] == nums[j])
//                     count++;
//             }
//         }
//         return count;
//     }
// };

// Time Complexity: O(n²) — we compare pairs using nested loops.
// Space Complexity: O(1) — only a counter and loop variables are used.