class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int i = 0, j = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        while(i < g.size() && j < s.size()){
            if(s[j] >= g[i])
                i++;
            j++;
        }
        return i;
    }
};

// Sort both
//    ↓
// cookie >= child?
//    ↓
// YES → satisfy child → i++
// NO  → discard cookie
//    ↓
// j++ always

// Time: O(n log n + m log m) because of sorting.
// Space: O(1) extra space apart from the sorting implementation.