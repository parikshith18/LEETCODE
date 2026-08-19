class Solution {
public:
    void helper(vector<int>& nums, vector<vector<int>>& ans,
    vector<int>& curr, int n){
        if(n == 0){
            ans.push_back(curr);
            return;
        }

        // Take
        curr.push_back(nums[n - 1]);
        helper(nums, ans, curr, n - 1);
        curr.pop_back();

        // Not Take
        helper(nums, ans, curr, n - 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        helper(nums, ans, curr, nums.size());
        return ans;
    }
};

// TAKE:
// Add the current element to the subset.
// Then recursively explore all possibilities with this element included.

// pop_back():
// BACKTRACK — remove the element we just took.
// This restores the previous state of curr.
// Now we can explore the NOT TAKE branch.

// NOT TAKE:
// Don't add the current element.
// Recursively explore all possibilities without this element.


// There are 2 choices (take/not take) for every element
// → 2^n subsets
// Each subset can contain up to n elements
// TC = O(n × 2^n)


// Recursion depth = n
// curr can contain at most n elements
// Auxiliary SC = O(n)

// If output is included:
// ans contains 2^n subsets, each up to n elements
// Output space = O(n × 2^n)