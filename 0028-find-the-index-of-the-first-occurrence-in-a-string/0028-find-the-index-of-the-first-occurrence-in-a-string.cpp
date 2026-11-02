class Solution {
public:
    vector<int> buildLPS(string needle){
        int m = needle.size(), i = 1, len = 0;
        vector<int> lps(m, 0);
        while(i < m){
            if(needle[i] == needle[len]){
                len++;
                lps[i] = len;
                i++;
            } else {
                if(len != 0){
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }

    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        int i = 0, j = 0;
        vector<int> lps = buildLPS(needle);

        // edge case.. 
        if(needle.empty())
            return 0;

        while(i < n){
            // Case 1: If characters match;
            if(haystack[i] == needle[j])
                i++, j++;

            // Case 2: If all characters got matched
            if(j == m){
                return i - j;
            
            // Case 3: If characters get mismatched
            } else if(i < n && haystack[i] != needle[j]){
                if(j != 0){
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        return -1;
    }
};

// KMP ALGO 
// Build the LPS Array using needle
// User that LPS array to search for needle in thast haystick
// LPS array - LONGEST PROPER PREFIX 

// LPS creation hengee?? 
// iga for ababc
// Prefix = a, ab, aba, abab
// SUffix = c, bc, abc, babc
// Nothing in common ... So, LPS = 0...

// iga for abab
// Prefix = a, ab, aba
// Suffix = b, ab, bab
// So common one is ab
// and its length is 2 .. 
// So, LPS = 2... 

// Time complexity: O(N + M)
// Space complexity: O(M) for the LPS array.