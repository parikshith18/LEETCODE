class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for(char c: s)
            freq[c]++;

        priority_queue<pair<int, char>> pq;
        for(auto it: freq)
            pq.push({it.second, it.first});

        string ans;
        while(!pq.empty()){
            int count = pq.top().first;
            char c = pq.top().second;
            pq.pop();  // very imp stmt

            for(int i = 0; i < count; i++){
                ans += c;
            }
        }
        return ans;
    }
};

// TC: O(n log u)
// SC: O(u), where u is the number of unique characters

// character -> frequency
//         ↓
// Max Heap
// highest frequency on top
//         ↓
// take character
//         ↓
// add it frequency times