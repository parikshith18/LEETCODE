class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int count = 0;
        for(int x: nums){
            count += mp[x - k];
            count += mp[x + k];
            mp[x]++;
        }
        return count;
    }
};

// Complexity: Average time O(n) and extra space O(n).

// BRUTE FORCE
// class Solution {
// public:
//     int countKDifference(vector<int>& nums, int k) {
//         int count = 0, n = nums.size();
//         for(int i = 0; i < n; i++){
//             for(int j = i + 1; j < n; j++){
//                 if(abs(nums[i] - nums[j]) == k)
//                     count++;
//             }
//         }
//         return count;
//     }
// };

// Complexities:
// - Time: O(n²) — two nested loops.
// - Extra space: O(1) — only a few variables.