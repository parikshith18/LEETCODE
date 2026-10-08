class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int sum = 0;
        mp[0] = -1;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            int rem = sum % k;
            if(mp.count(rem)){
                if(i - mp[rem] >= 2)
                    return true;
            } else {
                mp[rem] = i;
            }
        }
        return false;
    }
};

// TC: O(n) average
// SC: O(n)


// prefix sum
//     ↓
// remainder = sum % k
//     ↓
// same remainder seen before?
//     ↓
// yes → check length >= 2
//     ↓
// true


// BRUTE FORCE
// class Solution {
// public:
//     bool checkSubarraySum(vector<int>& nums, int k) {
//         int n = nums.size();
//         for(int i = 0; i < n; i++){
//             int sum = 0;
//             for(int j = i; j < n; j++){
//                 sum += nums[j];
//                 if(j - i + 1 >= 2 && sum % k == 0)
//                     return true;
//             }
//         }
//         return false;
//     }
// };
// Time Complexity: O(n²)
// Space Complexity: O(1)