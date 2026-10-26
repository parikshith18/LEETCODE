class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_set<int> st;
        for(char c: s){
            if(st.count(c))
                return c;
            st.insert(c);
        }
        return '?';
    }
};

// Time Complexity: O(n) average — we traverse the string once, with average O(1) set operations.
// Space Complexity: O(1) — the string contains only lowercase English letters, so at most 26 distinct characters are stored.

// BRUTE FORCE
// class Solution {
// public:
//     char repeatedCharacter(string s) {
//         int n = s.size();
//         for(int i = 0; i < n; i++){
//             for(int j = 0; j < ; j++){
//                 if(s[i] == s[j])
//                     return s[j];
//             }
//         }
//         return '?';
//     }
// };

// Time Complexity: O(n²) — in the worst case, each character is compared with all earlier characters.
// Space Complexity: O(1) — only a few extra variables are used.