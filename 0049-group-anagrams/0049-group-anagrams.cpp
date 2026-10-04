class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;
        for(string s: strs){
            string key = s;
            sort(key.begin(), key.end());
            mp[key].push_back(s);
        }

        for(auto it: mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
// Time Complexity: O(n × k log k), where n is the number of strings and k is the maximum length of a string.
// Space Complexity: O(n × k), because we store all the strings in the HashMap groups and answer.