class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        sort(nums.begin(), nums.end());
        int median = nums[n/2];
        for(int i = 0; i < n; i++){
            sum += abs(nums[i] - median);
        }
        return sum;
    }
};

// First Sort, Then find the Median element
// then increase or decrease all other array elements to that median 
// for ex ... nums = [1, 2, 3]
// already sorted ... 
// median = 2
// 1 = 1, 2 = 0, 3 = 1
// so 1 + 1, ans = 2.. 

// Complexity:
// - Time: O(N log N) — sorting dominates.
// - Auxiliary space: O(1) for the algorithm apart from sorting implementation details.