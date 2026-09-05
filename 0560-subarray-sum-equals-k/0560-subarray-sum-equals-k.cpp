class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n =  nums.size();
        int ans = 0, sum = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            if(mp.count(sum - k))
                ans += mp[sum - k];
            mp[sum]++;
        }
        return ans;
    }
};

// The approach is to use prefix sum and a HashMap. We keep adding elements to get the current prefix sum and store how many times each prefix sum has appeared. For every current sum, we check whether current sum minus k has appeared before, because current sum minus previous sum gives the sum of the subarray between them. If it exists, we add its frequency to the answer because each occurrence represents a valid subarray. We initialize prefix sum 0 with frequency 1 so that subarrays starting from index 0 are also counted. Time Complexity: O(n) average, Space Complexity: O(n).
