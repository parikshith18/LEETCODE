class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size(), maxi = 0;
        int left = 0, right = n - 1;
        while(left < right){
            int width = right - left;
            int h = min(height[left], height[right]);
            int area = width * h;
            maxi = max(maxi, area);

            if(height[left] < height[right])
                left++;
            else
                right--;
        }
        return maxi;
    }
};