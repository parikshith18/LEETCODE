class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> mp;
        int ans = 0;
        for(int x: nums1){
            for(int y: nums2)
                mp[x + y]++;
        }

        for(int x: nums3){
            for(int y: nums4){
                int need = -(x + y);
                if(mp.count(need))
                    ans += mp[need];
            }
        }
        return ans;
    }
};

// Time Complexity: O(n²) average, because we calculate all pairs from A and B and all pairs from C and D.
// Space Complexity: O(n²), because in the worst case the HashMap stores all A + B pair sums.

// A + B
//    ↓
// calculate all sums
//    ↓
// store frequency in HashMap

// C + D
//    ↓
// calculate sum
//    ↓
// find its opposite in HashMap
//    ↓
// add its frequency


