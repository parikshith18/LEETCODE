class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if(n > m)
            return false;

        vector<int> need(26, 0), window(26, 0);
        for(char c: s1)
            need[c - 'a']++;
        
        int left = 0;
        for(int right = 0; right < m; right++){
            window[s2[right] - 'a']++;
            if(right - left + 1 > n){
                window[s2[left] - 'a']--;
                left++;
            }
            if(window == need)
                return true;
        }
        return false;
    }
};

// s1 frequency
//       ↓
// fixed window = s1.length()
//       ↓
// add right character
//       ↓
// window too big?
//       ↓
// remove left character
//       ↓
// compare frequencies
//       ↓
// same → TRUE