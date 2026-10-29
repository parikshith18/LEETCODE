class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;

        int count = 0, odd = 0;
        for(int x: nums){
            if(x % 2 != 0)  
                odd++;
            count += mp[odd - k];
            mp[odd]++;
        }
        return count;
    }
};

// Time Complexity: O(n) average
// Extra Space: O(n)



// BRUTE FORCE
// class Solution {
// public:
//     int numberOfSubarrays(vector<int>& nums, int k) {
//         int count = 0, n = nums.size();
//         for(int i = 0; i < n; i++){
//             int odd = 0;
//             for(int j = i; j < n; j++){
//                 if(nums[j] % 2 != 0)
//                     odd++;
//                 if(odd == k)
//                 count++;
//             }
//         }
//         return count;
//     }
// };

// Time Complexity: O(n²)
// Extra Space: O(1)