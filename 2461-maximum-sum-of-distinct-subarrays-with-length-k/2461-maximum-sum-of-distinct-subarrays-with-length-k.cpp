class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        long long ans = 0, sum = 0;
        int n = nums.size(), left = 0;
        for(int right = 0; right < n; right++){
            sum += nums[right];
            mp[nums[right]]++;

            if(right - left + 1 > k){
                sum -= nums[left];
                mp[nums[left]]--;
                if(mp[nums[left]] == 0)
                    mp.erase(nums[left]);
                left++;
            }

            if(right - left + 1 == k && mp.size() == k){
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};

// Time Complexity: O(n) average — Each element enters and leaves the sliding window at most once. HashMap operations take O(1) average time.
// Space Complexity: O(k) — The HashMap stores at most k distinct elements in the current window.



// BRUTE FORCE 
// class Solution {
// public:
//     long long maximumSubarraySum(vector<int>& nums, int k) {
//         int n = nums.size();
//         long long ans = 0;
//         for(int i = 0; i <= n - k; i++){
//             long long sum = 0;
//             bool distinct = true;
//             unordered_set<int> st;
//             for(int j = i; j < i + k; j++){
//                 if(st.count(nums[j])){
//                     distinct = false;
//                     break;
//                 }
//                 st.insert(nums[j]);
//                 sum += nums[j];
//             }
//             if(distinct)
//                 ans = max(ans, sum);
//         }
//         return ans;
//     }
// };

// Complexity:
// - Time: O(n × k) average.
// - Space: O(k) for the unordered_set.