class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(int x: nums)
            st.insert(x);

        int maxi = 0;
        for(int x: st){
            if(!st.count(x - 1)){
                int start = x, count = 1;
                while(st.count(start + 1)){
                    start++;
                    count++;
                }
                maxi = max(maxi, count);
            }
        }
        return maxi;
    }
};
// TC: O(n) average
// SC: O(n)

// x-1 absent
//    ↓
// x is starting point
//    ↓
// keep checking x+1
//    ↓
// while consecutive
//    ↓
// count length

// BRUTE FORCE
// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         int n = nums.size();
//         if(nums.empty())
//             return 0;
        
//         sort(nums.begin(), nums.end());
//         int count = 1, maxi = 1;
//         for(int i = 1; i < n; i++){
//             if(nums[i] == nums[i - 1] + 1)
//                 count++;
//             else if(nums[i] == nums[i - 1])
//                 continue;
//             else
//                 count = 1;

//             maxi = max(maxi, count);
//         }
//         return maxi;
//     }
// };

// TC: O(n log n)
// SC: O(1) extra space.