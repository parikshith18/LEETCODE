class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> st;
        int count = 0;
        for(char c: jewels)
            st.insert(c);

        for(char s: stones){
            if(st.count(s))
                count++;
        }
        return count;
    }
};

// Time Complexity: O(J + S) — we insert all jewels and check all stones, with average O(1) HashSet operations.
// Space Complexity: O(J) — the set stores the distinct jewel characters.

// BRUTE FORCE
// class Solution {
// public:
//     int numJewelsInStones(string jewels, string stones) {
//         int count = 0;
//         for(char c: stones){
//             for(char s: jewels){
//                 if(c == s){
//                     count++;
//                     break;
//                 }
//             }
//         }
//         return count;
//     }
// };

// Time: O(S × J) — each stone may be compared with every jewel.
// Space: O(1) — only a few variables are used.