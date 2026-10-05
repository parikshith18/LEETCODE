class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            if(mp.count(nums[i]))
                if(i - mp[nums[i]] <= k)
                    return true;
            
            mp[nums[i]] = i;
        }
        return false;
    }
};
// Time Complexity: O(n) average
// Space Complexity: O(n)

// BRUTE FORCE
// class Solution {
// public:
//     bool containsNearbyDuplicate(vector<int>& nums, int k) {
//         int n = nums.size();
//         for(int i = 0; i < n; i++){
//             for(int j = i + 1; j < n; j++){
//                 if(nums[i] == nums[j] && j - i <= k)
//                     return true;
//             }
//         }
//         return false;
//     }
// };

// TC: O(n²)
// SC: O(1)