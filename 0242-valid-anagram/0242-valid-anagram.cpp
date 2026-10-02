class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
            
        int freq[26] = {0};
        for(char x: s)
            freq[x - 'a']++;

        for(char x: t){
            freq[x - 'a']--;

        if(freq[x - 'a'] < 0)
            return false;
        }
        return true;
    }
};
// Time Complexity: O(n)
// Space Complexity: O(1)

// BRUTE FORCE
// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         if(s.size() != t.size())
//             return false;
//         sort(s.begin(), s.end());
//         sort(t.begin(), t.end());
//         return s == t;
//     }
// };
// Time Complexity: O(n log n)
// Space Complexity: O(1)