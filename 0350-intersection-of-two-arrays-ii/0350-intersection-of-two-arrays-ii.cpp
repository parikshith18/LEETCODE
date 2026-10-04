class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        vector<int> ans;
        for(int x: nums1)
            mp[x]++;

        for(int x: nums2){
            if(mp[x] > 0){
                ans.push_back(x);
                mp[x]--;
            }
        }
    return ans;
    }
};
// TC: O(n + m) average
// SC: O(n)


// BRUTE FORCE
// class Solution {
// public:
//     vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
//         vector<int> ans;
//         vector<bool> used(nums2.size(), false);

//         for(int i = 0; i < nums1.size(); i++){
//             for(int j = 0; j < nums2.size(); j++){
//                 if(nums1[i] == nums2[j] && !used[j]){
//                     ans.push_back(nums1[i]);
//                     used[j] = true;
//                     break;
//                 }
//             }
//         }
//         return ans;
//     }
// };

// Time Complexity: O(n × m)
// Space Complexity: O(m) for the used array.