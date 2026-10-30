class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        unordered_map<int, int> mp;
        mp[0] = 1;

        long long count = 0, sum = 0;
        for(int x: arr){
            sum += x;
            int parity = sum % 2;
            count += mp[1 - parity];
            mp[parity]++;
        }
        return count % 1000000007;
    }
};

// Time Complexity: O(n) average
// Space Complexity: O(1)

// BRUTE FORCE
// class Solution {
// public:
//     int numOfSubarrays(vector<int>& arr) {
//         int n = arr.size();
//         long long count = 0;
//         for(int i = 0; i < n; i++){
//             long long sum = 0;
//             for(int j = i; j < n; j++){
//                 sum += arr[j];
//                 if(sum % 2 != 0)
//                     count++;
//             }
//         }
//         return count % 1000000007;
//     }
// };

// Time Complexity: O(n²)
// Space Complexity: O(1)