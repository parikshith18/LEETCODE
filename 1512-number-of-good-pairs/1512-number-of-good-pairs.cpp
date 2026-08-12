class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size(), count = 0;
        unordered_map <int, int> freq;
        for(int i = 0; i < n; i++){
            count += freq[nums[i]];
            freq[nums[i]]++;
        }
        return count;
    }
};