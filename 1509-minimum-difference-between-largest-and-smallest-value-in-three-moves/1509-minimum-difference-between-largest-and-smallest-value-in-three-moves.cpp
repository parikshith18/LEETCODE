
class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();

        // If there are 4 or fewer elements, we can make
        // all elements equal using at most 3 moves.
        if (n <= 4)
            return 0;

        // Sort the array so the smallest elements are
        // at the beginning and the largest at the end.
        sort(nums.begin(), nums.end());

        int ans = INT_MAX;

        // We have 4 possibilities:
        // 1. Change the 3 largest elements.
        // 2. Change the 1 smallest and 2 largest elements.
        // 3. Change the 2 smallest and 1 largest elements.
        // 4. Change the 3 smallest elements.
        for (int i = 0; i < 4; i++) {

            // Calculate the remaining range after changing
            // i smallest elements and (3 - i) largest elements.
            int diff = nums[n - 4 + i] - nums[i];

            // Keep the minimum difference among all 4 cases.
            ans = min(ans, diff);
        }

        // Return the smallest possible difference.
        return ans;
    }
};

// Time Complexity: O(n log n) - sorting the array.
// Auxiliary Space: O(log n) - sorting stack space, typically.
