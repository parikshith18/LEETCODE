class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int ans = 0, sum = 0;
        mp[0] = 1; // very imp line
        for(int x : nums){
            sum += x;
            int rem = (sum % k + k) % k;
            if(mp.count(rem))
                ans += mp[rem];
            mp[rem]++;
        }
        return ans;
    }
};

// TC: O(n) average
// SC: O(k) because there are at most k possible remainders.

// Add current number to sum
//         ↓
// Find remainder
//         ↓
// Have we seen this remainder before?
//         ↓
// Yes → add its frequency to ans
//         ↓
// Increase frequency of this remainder