class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int left = 0, n = nums.size();
        double maxi = INT_MIN, sum = 0;
        for(int right = 0; right < n; right++){
            sum += nums[right];
            if(right - left + 1 > k){
                sum -= nums[left];
                left++;
            }
            if(right - left + 1 == k){
                maxi = max(maxi, sum);
            }
        }
        return maxi/k;
    }
};