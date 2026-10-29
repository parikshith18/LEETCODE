class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;

        int sum = 0, count = 0;
        for(int x: nums){
            sum += x;
            count += mp[sum - k];
            mp[sum]++;
        }
        return count;
    }
};

// Time Complexity: O(n) average
// Space Complexity: O(n)

// BRUTE FORCE
// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         int count = 0, n = nums.size();
//         for(int i = 0; i < n; i++){
//             int sum = 0;
//             for(int j = i; j < n; j++){
//                 sum += nums[j];
//                 if(sum == k)
//                     count++;
//             }
//         }
//         return count;
//     }
// };

// Time Complexity: O(n²)
// Space Complexity: O(1)