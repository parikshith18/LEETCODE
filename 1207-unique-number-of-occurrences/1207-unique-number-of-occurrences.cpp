class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp;
        unordered_set<int> st;
        
        for(int x: arr)
            mp[x]++;

        for(auto it: mp){
            if(st.count(it.second))
                return false;
            st.insert(it.second);
        }
        return true;
    }
};

// Time Complexity: O(n) average — we count frequencies and check each distinct frequency using hash-based operations.
// Space Complexity: O(n) — the HashMap and HashSet may each store up to n entries.