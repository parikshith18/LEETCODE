class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size(), m = t.size();
        if(n != m) // Egde Case
            return false; 

        vector<int> freq(26);
        for(char c: s)
            freq[c - 'a']++;
        for(char c: t)
            freq[c - 'a']--;

        for(int x: freq)
            if(x != 0)
                return false;
        return true;
    }
};

// s → ++
// t → --

// everything 0 → anagram ✅
// anything != 0 → false ❌