class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int x: nums)
            freq[x]++;

        priority_queue<pair<int, int>> pq;
        for(auto it: freq)
            pq.push({it.second, it.first});

        vector<int> ans;
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
// Time Complexity: O(n + m log m)
// Space Complexity: O(m)


// BRUTE FORCE
// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         unordered_map<int, int> freq;
//         for(int x: nums)
//             freq[x]++;
        
//         vector<pair<int, int>> arr;
//         for(auto it: freq){
//             arr.push_back({it.second, it.first});
//         }
//         sort(arr.rbegin(), arr.rend());

//         vector<int> ans;
//         for(int i = 0; i < k; i++){
//             ans.push_back(arr[i].second);
//         }
//         return ans;
//     }
// };
// TC AND SC FOR THIS
// Time Complexity: O(n + m log m), where n is the size of nums and m is the number of unique elements.

// Space Complexity: O(m), because we store m unique elements in the HashMap and vector.

