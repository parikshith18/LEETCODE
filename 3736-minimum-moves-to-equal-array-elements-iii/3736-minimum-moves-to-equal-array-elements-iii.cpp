class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        int maxi = *max_element(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            sum += (maxi - nums[i]);
        }
        return sum;
    }
};

// Complexity
// - Time: O(N) — finding maximum takes O(N), and the loop takes O(N).
// - Space: O(1) — only a few variables are used.