class Solution {
public:
    void helper(vector<int> &nums, vector<vector<int>> &ans,
    vector<int> &curr, int start){
        ans.push_back(curr);
        for(int i = start; i < nums.size(); i++){
            if(i > start && nums[i] ==  nums[i - 1])
                continue;

            curr.push_back(nums[i]);
            helper(nums, ans, curr, i + 1);
            curr.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> curr;
        helper(nums, ans, curr, 0);
        return ans;
    }
};

// Sort the array first.
// This puts all duplicate elements next to each other,
// which allows us to detect and skip duplicates.

// Start from index 0 and build the subset recursively.

// At every recursion level, use a for loop to try
// every possible element from 'start' onwards.

// When we choose an element:
// 1. Add it to curr        → TAKE
// 2. Recursively explore   → explore all subsets after it
// 3. Remove it from curr   → BACKTRACK / undo TAKE

// The for loop automatically handles NOT TAKE:
// If we don't choose an element, the loop simply moves
// to the next element.

// Important duplicate rule:
// If the current element is the same as the previous element
// AND both are being considered at the SAME recursion level,
// skip the current element.

// This prevents generating the same subset multiple times.

// But duplicates are allowed at DIFFERENT recursion levels.
// Example: [2,2] is valid because we can TAKE the first 2
// and then TAKE the second 2 in the next recursion level.

// Add curr to the answer at every recursion level,
// because every current subset is a valid subset.

// TAKE → add element → recurse → remove element
// NOT TAKE → loop moves to the next choice

// TC = O(N × 2^N)
// There can be up to 2^N subsets,
// and copying each subset can take O(N).

// SC = O(N) auxiliary space for recursion + current subset.
// Output space is O(N × 2^N).