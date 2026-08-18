class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;

        for(int x: nums)
            freq[x]++;
        int ans = -1;

        for(int i = 0; i < n; i++){
            bool valid = false;
            if(k == n) // Case 1
                valid = true;
            else if(k == 1 && freq[nums[i]] == 1) // Case 2
                valid = true;
            else if(k > 1 && freq[nums[i]] == 1 &&
            (i == 0 || i == n - 1)) // Case 3
                valid = true;
            
            if(valid)
                ans = max(ans, nums[i]);
        }
        return ans;
    }
};

// CASE 1: k == n
// → every number is valid
// → take maximum

// CASE 2: k == 1
// → only numbers appearing once are valid
// → take maximum

// CASE 3: 1 < k < n
// → only FIRST and LAST can be valid
// → and they must appear once
// → take maximum