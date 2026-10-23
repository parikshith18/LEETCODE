class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int x: nums)
            mp[x]++;

        for(int x: nums){
            if(mp[x] == 1)
                return x;
        }
        return -1;
    }
};
// Time Complexity: O(n) — we traverse the array twice, and hash-map operations take O(1) time on average.
// Space Complexity: O(n) — in the worst case, the hash map stores up to n distinct numbers.


// BRUTE FORCE
// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         int n = nums.size();
//         for(int i = 0; i < n; i++){
//             int count = 0;
//             for(int j = 0; j < n; j++){
//                 if(nums[i] == nums[j])
//                     count++;
//             }
//             if(count == 1)
//                 return nums[i];
//         }
//         return -1;
//     }
// };

// Time Complexity: O(n²) — for each element, we scan the entire array.
// Space Complexity: O(1) — we use only a few extra variables.