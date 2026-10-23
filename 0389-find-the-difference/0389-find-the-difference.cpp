class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<int, int> mp;
        for(char c: s)
            mp[c]++;

        for(char c: t){
            if(mp[c] == 0)
                return c;
            mp[c]--;
        }
        return '?';
    }
};
// Time: O(n) — both strings are traversed once on average.
// Space: O(1) — assuming a fixed character set; otherwise, O(u), where u is the number of distinct characters.

// BRUTE FORCE
// class Solution {
// public:
//     char findTheDifference(string s, string t) {
//         vector<int> used(s.size(), false);
//         for(int c: t){
//             bool found = false;
//             for(int i = 0; i < s.size(); i++){
//                 if(s[i] == c & !used[i]){
//                     used[i] = true;
//                     found = true;
//                     break;
//                 }
//             }

//             if(!found)
//                 return c;
//         }
//             return '?';
//     }
// };

// Time Complexity: O(n²) — for each character in t, we may scan all characters in s.
// Space Complexity: O(n) — the used vector stores whether each character in s has been matched.