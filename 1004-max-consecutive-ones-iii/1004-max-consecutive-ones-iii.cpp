class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size(), left = 0, zeroes = 0, maxi = 0;
        for(int right = 0; right < n; right++){
            if(nums[right] == 0)
                zeroes++;
            while(zeroes > k){
                if(nums[left] == 0)
                    zeroes--;
                left++;
            }
            maxi = max(maxi, right - left + 1);
        }
        return maxi;
    }
};