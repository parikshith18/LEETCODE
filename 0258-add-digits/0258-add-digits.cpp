class Solution {
public:
    int helper(int num){
        int sum = 0;
        while(num > 0){
            int digit = num % 10;
            sum += digit;
            num /= 10;
        }
        return sum;
    }

    int addDigits(int num) {
        int sum = helper(num);
        while(sum > 9)
            sum = helper(sum);
        return sum;
    }
};