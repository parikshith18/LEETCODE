class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        unordered_map<int, long long> mp;
        mp[0] = 1;
        long long sum = 0, count = 0;
        for(int x: nums){
            sum ^= x;
            count += mp[sum];
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
//     long long beautifulSubarrays(vector<int>& nums) {
//         long long count = 0;
//         int n = nums.size();
//         for(int i = 0; i < n; i++){
//             long long sum = 0;
//             for(int j = i; j < n; j++){
//                 sum ^= nums[j];
//                 if(sum == 0)
//                     count++;
//             }
//         }
//         return count;
//     }
// };

// Time Complexity: O(n²)
// Space Complexity: O(1)