class Solution {
public:
    bool equalFrequency(string word) {
        unordered_map<char, int> freq;
        for(char c: word)
            freq[c]++;

        int n = word.size();
        for(int i = 0; i < n; i++){
            freq[word[i]]--;
            if(freq[word[i]] == 0)
                freq.erase(word[i]);

            unordered_set<int> st;
            for(auto it: freq)
                st.insert(it.second);
            if(st.size() == 1)
                return true;
            freq[word[i]]++;
        }
        return false;
    }
};

// Time Complexity:
// O(n) average

// Space Complexity:
// O(n)