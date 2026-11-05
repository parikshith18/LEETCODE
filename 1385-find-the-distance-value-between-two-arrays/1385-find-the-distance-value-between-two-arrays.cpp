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