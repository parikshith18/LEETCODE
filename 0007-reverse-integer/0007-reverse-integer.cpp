class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while(x != 0){
            int digit = x % 10; // Store Last Digit
            if(ans > INT_MAX / 10 || ans < INT_MIN / 10)
                return 0; // Condition Constraint
            ans = ans * 10 + digit;
            x /= 10;
        }
        return ans;
    }
};