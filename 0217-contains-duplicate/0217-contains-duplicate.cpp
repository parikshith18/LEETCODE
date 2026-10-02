// OPTIMAL APPROACH 
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set <int> st;
        for(int x: nums){
            if(st.count(x))
                return true;
            st.insert(x);
        }
        return false;
    }
};
// Time Complexity: O(n) average
// Space Complexity: O(n)


// BRUTE FORCE
// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//         int n = nums.size();
//         for(int i = 0; i < n; i++){
//             for(int j = i + 1; j < n; j++){
//                 if(nums[i] == nums[j])
//                     return true;
//             }
//         }
//         return false;
//     }
// };
// Time: O(n²)
// Space: O(1)