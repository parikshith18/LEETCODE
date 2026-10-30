class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        unordered_set<long long> st;
        st.insert(0);
        long long sum = 0;
        int count = 0;
        for(int x: nums){
            sum += x;
            if(st.count(sum - target)){
                count++;
                sum = 0;
                st.clear();
                st.insert(0);
            } else {
                st.insert(sum);
            }
        }
        return count;
    }
};

// Time Complexity: O(n) average
// Space Complexity: O(n)