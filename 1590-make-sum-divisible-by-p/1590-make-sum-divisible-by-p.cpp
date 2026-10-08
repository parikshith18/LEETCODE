class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long total = 0;

        for(int x: nums)
            total += x;
        
        int need = total % p;
        if(need == 0)
            return 0;

        unordered_map<int, int> mp;
        mp[0] = -1;
        int rem = 0, ans = n + 1;
        for(int i = 0; i < n; i++){
            rem = (rem + nums[i]) % p;
            int target = (rem - need + p) % p;
            if(mp.count(target))
                ans = min(ans, i - mp[target]);
            mp[rem] = i;
        }
        return ans == n? -1 : ans;
    }
};

// total sum % p
//       ↓
// need = remainder to remove

// current prefix remainder
//       ↓
// find previous remainder = current - need
//       ↓
// valid subarray found
//       ↓
// keep minimum length

// TC: O(n) average
// SC: O(n)