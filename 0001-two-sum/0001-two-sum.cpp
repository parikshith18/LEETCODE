// OPTIMAL APPROACH
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            int need = target - nums[i];
            if(mp.count(need))
                return {mp[need], i};
            mp[nums[i]] = i;
        }
        return {};
    }
};
// Time Complexity: O(n) 
// Space Complexity: O(n)

// BRUTE FORCE
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int n = nums.size();
//         for(int i = 0; i < n; i++){
//             for(int j = i + 1; j < n; j++){
//                 if(nums[i] + nums[j] == target)
//                     return {i, j};
//             }
//         }
//         return {};
//     }
// };
// TC: O(n²)
// SC: O(1)