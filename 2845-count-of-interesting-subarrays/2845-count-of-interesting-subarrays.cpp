class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        unordered_map<int, long long> mp;
        mp[0] = 1;
        int prefix = 0, n = nums.size(); 
        long long ans = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] % modulo == k)
                prefix++;
            int rem = (prefix - k + modulo) % modulo;
            ans += mp[rem];
            mp[prefix % modulo]++;
        }
        return ans;
    }
};

// Time Complexity: O(n) average

// - We traverse the array only once using a single loop.
// - Each HashMap operation (`find`, insert/update) takes O(1) average time.
// - Therefore, total time complexity is O(n).

// Space Complexity: O(min(n, modulo))

// - We use an unordered_map to store prefix remainders and their frequencies.
// - At most `min(n, modulo)` distinct remainders are stored.

// Final:

// - Time Complexity: O(n) average
// - Space Complexity: O(min(n, modulo))


// BRUTE FORCE
// class Solution {
// public:
//     long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
//         int n = nums.size();
//         long long ans = 0;
//         for(int i = 0; i < n; i++){
//             long long count = 0;
//             for(int j = i; j < n; j++){
//                 if(nums[j] % modulo == k){
//                     count++;
//                 }
//                 if(count % modulo == k){
//                     ans++;
//                 }
//             }
//         }
//         return ans;
//     }
// };

// Complexity
// - Time Complexity: O(n²) — two nested loops.
// - Space Complexity: O(1) — only a few variables.