class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map <int, int> freq;
        for(int x: arr)
            freq[x]++;

        int maxi = -1;
        for(auto it: freq){
            if(it.first == it.second)
                maxi = max(maxi, it.first);
        }
        return maxi;
    }
};

// Time: (O(n)) average — one pass to count, one pass over distinct numbers.
// Space: (O(n)) — the HashMap stores distinct numbers and their frequencies.