class Solution {
public:
    // AT MOST K - AT MOST K-1 APPROACH 
    int atmost(vector<int> &nums, int k){
        int left = 0, n = nums.size();
        int cnt = 0;
        unordered_map<int, int> mp;
        for(int right = 0; right < n; right++){
            mp[nums[right]]++;
            while(mp.size() > k){
                mp[nums[left]]--;
                if(mp[nums[left]] == 0)
                    mp.erase(nums[left]);
                left++;
            }
            cnt += right - left + 1;
        }
        return cnt;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums, k) - atmost(nums, k - 1);
    }
};