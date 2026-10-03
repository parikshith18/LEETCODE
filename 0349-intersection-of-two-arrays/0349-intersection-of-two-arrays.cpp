class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st;
        vector<int> ans;
        for(int x: nums2)
            st.insert(x);

        for(int x: nums1){
            if(st.count(x))
                ans.push_back(x);
                st.erase(x);
        }
        return ans;
    }
};
// Time Complexity: O(n + m) average
// Space Complexity: O(m), where m is the size of nums2.