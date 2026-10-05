class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int> st;
        for(int x: nums)
            st.insert(x);

        for(int i = 0; i <= nums.size(); i++){
            if(!st.count(i))
                return i;
        }
        return -1;
    }
};
// Time Complexity: O(n) average
// Space Complexity: O(n)


// BRUTE FORCE
// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         int n = nums.size();
//         for(int i = 0; i <= n; i++){
//             bool found = false;
//             for(int j = 0; j < n; j++){
//                 if(nums[j] == i){
//                     found = true;
//                     break;
//                 }
//             }

//             if(!found)
//                 return i;
//         }
//         return -1;
//     }
// };
// Time Complexity: O(n²)
// Space Complexity: O(1)