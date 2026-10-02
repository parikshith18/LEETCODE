class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mp;
        for(char c: magazine)
            mp[c]++;

        for(char c: ransomNote){
            if(mp[c] == 0)
                return false;
            mp[c]--;
        }
        return true;
    }
};
// Time Complexity: O(n + m), 
// Space Complexity: O(u), where u is the number of distinct characters in magazine. For lowercase English letters, u is at most 26, so effectively O(1).



// BRUTE FORCE
// class Solution {
// public:
//     bool canConstruct(string ransomNote, string magazine) {
//         for(char c: ransomNote){
//             int pos = magazine.find(c);
//             if(pos == string::npos)
//                 return false;
//             magazine.erase(pos, 1);
//         }
//         return true;
//     }
// };

// Time Complexity: O(n × m)
// Space Complexity: O(m)