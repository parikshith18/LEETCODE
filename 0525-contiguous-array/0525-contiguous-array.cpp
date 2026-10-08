class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int maxi = 0, sum = 0;
        mp[0] = -1; // very imp line
        for(int i = 0; i < n; i++){
            if(nums[i] == 0)
                sum--;
            else
                sum++;

            if(mp.count(sum))
                maxi = max(maxi, i - mp[sum]);
            else
                mp[sum] = i;
        }
        return maxi;
    }
};
// TC: O(n) average
// SC: O(n)


// BRUTE FORCE
// class Solution {
// public:
//     int findMaxLength(vector<int>& nums) {
//         int n = nums.size();
//         int maxi = 0;
//         for(int i = 0; i < n; i++){
//             int ones = 0, zeroes = 0;
//             for(int j = i; j < n; j++){
//                 if(nums[j] == 0)
//                     zeroes++;
//                 else 
//                     ones++;

//                 if(zeroes == ones)
//                     maxi = max(maxi, j - i + 1);
//             }
//         }
//         return maxi;
//     }
// };
// Time Complexity: O(n²)
// Space Complexity: O(1)