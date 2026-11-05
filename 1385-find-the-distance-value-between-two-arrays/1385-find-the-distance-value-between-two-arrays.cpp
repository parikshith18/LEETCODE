class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n = arr1.size(), m = arr2.size();
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());
        int i = 0, j = 0, count = 0;
        while(i < n){
            int low = arr1[i] - d;
            int high = arr1[i] + d;
            while(j < m && arr2[j] < low)
                j++;
            if(j == m || arr2[j] > high)
                count++;
            i++;
        }
        return count;
    }
};

// Optimal — Sorting + Two Pointers
// - Sorting arr1: O(N log N)
// - Sorting arr2: O(M log M)
// - Two-pointer traversal: O(N + M) — i moves at most N times and j moves at most M times.
// TC - O(N log N + M log M)


// 1. Sort both arrays.
// 2. Take one element x from arr1.
// 3. Calculate its forbidden range:
//    [x-d, x+d]
// 4. Move pointer j forward until arr2[j] >= low.
// 5. If j reaches the end OR arr2[j] > high:
//    Accept x.
//    Otherwise:
//    Reject x.


// BRUTE FORCE
// class Solution {
// public:
//     int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
//         int n = arr1.size(), m = arr2.size();
//         int count = 0;
//         for(int i = 0; i < n; i++){
//             bool valid = true;
//             for(int j = 0; j < m; j++){
//                 if(abs(arr1[i] - arr2[j]) <= d){
//                     valid = false;
//                     break;
//                 }
//             }
//             if(valid)
//                 count++;
//         }
//         return count;
//     }
// };


// Time: O(N × M) — nested loops compare every element of both arrays in the worst case.
// Auxiliary Space: O(1) — only count and valid variables are used.