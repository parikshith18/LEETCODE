class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, maxi = 0;
        int n = s.size();
        vector<int> last(256, -1);
        for(int right = 0; right < n; right++){
            if(last[s[right]] != -1)
                left = max(left, last[s[right]] + 1);
            last[s[right]] = right;
            maxi = max(maxi, right - left + 1);
        }
        return maxi;
    }
};