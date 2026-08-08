class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 0, element = 0;
        for(int i = 0; i < n; i++){
            if(count == 0)
                element = nums[i];
            if(nums[i] == element)
                count++;
            else 
                count--;
        }

        //VERIFICATION 
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == element)
                cnt++;
        }

        if(cnt > n/2)
            return element;
        return -1;
    }
};