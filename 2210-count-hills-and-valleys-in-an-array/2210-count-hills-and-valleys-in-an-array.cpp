class Solution {
public:
    int countHillValley(vector<int>& nums) {
        // remove duplicate values
        vector<int> arr;
        for(int x: nums){
            if(arr.empty() || arr.back() != x)
                arr.push_back(x);
        }

        // count hill and valley
        int n = arr.size(), count = 0;
        for(int i = 1; i < n - 1; i++){
            if(arr[i] > arr[i - 1] &&
            arr[i] > arr[i + 1]){
                count++;
            } else if(arr[i] < arr[i - 1] &&
            arr[i] < arr[i + 1]){
                count++;
            }
        }
        return count;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)