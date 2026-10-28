class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> freq;
        for(string x: arr)
            freq[x]++;

        for(string x: arr){
            if(freq[x] == 1){
                k--;
                if(k == 0)
                    return x;
            }
        }
        return "";
    }
};

// Complexity
// - Time: O(n) average, assuming average constant-time HashMap operations and bounded string lengths.
// - Extra space: O(n) for the HashMap.