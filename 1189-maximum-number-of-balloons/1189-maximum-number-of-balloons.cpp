class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> freq;
        for(char c: text)
            freq[c]++;

        return min({
            freq['b'], freq['a'],
            freq['l']/2, freq['o']/2,
            freq['n']
        });
    }
};

// Complexity
// - Time: (O(n)) average.
// - Space: (O(1)), because the map stores at most the fixed number of possible characters (bounded by the character set).