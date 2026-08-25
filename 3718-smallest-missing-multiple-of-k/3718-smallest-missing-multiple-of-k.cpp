class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set <int> st;
        for(int x: nums)
            st.insert(x);
        
        for(int i = 1; ; i++){
            int x = k * i;
            if(!st.count(x))
                return x;
        }
    }
};