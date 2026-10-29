class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> mp;
        mp[0] = 1;

        int count = 0, sum = 0;
        for(int x: nums){
            sum += x;
            count += mp[sum - goal];
            mp[sum]++;
        }
        return count;
    }
};

// Time: O(n) average
// Extra space: O(n)

// BRUTE FORCE
// class Solution {
// public:
//     int numSubarraysWithSum(vector<int>& nums, int goal) {
//         int count = 0, n = nums.size();
//         for(int i = 0; i < n; i++){
//             int sum = 0;
//             for(int j = i; j < n; j++){
//                 sum += nums[j];
//                 if(sum == goal)
//                     count++;
//             }
//         }
//         return count;
//     }
// };

// // Time: O(n²)
// // Extra space: O(1)