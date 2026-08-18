class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int n = p.size(), m = s.size();
        if(n > m)
            return ans;
        
        vector<int> need(26, 0), window(26, 0);
        for(char c: p)
            need[c - 'a']++;
        
        int left = 0;
        for(int right = 0; right < m; right++){
            window[s[right] - 'a']++;
            if(right - left + 1 > n){
                window[s[left] - 'a']--;
                left++;
            }
            if(window == need)
                ans.push_back(left);
        }
        return ans;
    }
};

// p frequency
//     ↓
// fixed window = p.size()
//     ↓
// add right
//     ↓
// window too big?
//     ↓
// remove left
//     ↓
// frequency same?
//     ↓
// YES → store left