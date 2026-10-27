class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        unordered_map <char, int> mp;
        // first word du freq store maadu
        for(char c: words[0])
            mp[c]++;

        // second word indha compare maadkond hoogu each letter
        // in each word compare maadodhu .. same idre freq increase
        vector<string> ans;
        int n = words.size();

        for(auto it: mp){
            char p = it.first;
            int count = it.second;
            
            for(int i = 1; i < n; i++){
                int freq = 0;
                for(char x: words[i]){
                    if(x == p)
                        freq++;
                }
                count = min(count, freq);
            }
            while(count > 0){
                ans.push_back(string(1, p));
                count--;
            }
        }
        return ans;
    }
};

// Complexity
// - Time: (O(k times n times m)), where (k) is the number of distinct characters in the first word, (n) is the number of words, and (m) is the maximum word length.
// - Extra space: (O(k)) for the map, excluding the output.