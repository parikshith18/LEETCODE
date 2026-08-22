class Solution {
public:
    // since its integer we have to right our own reverse logic 
    int reverse(int num){
        int reverse = 0;
        while(num > 0){
            int digit = num % 10;
            reverse = reverse * 10 + digit;
            num /= 10;
        }
        return reverse;
    }

    bool sumOfNumberAndReverse(int num) {
        for(int i = 0; i <= num; i++){
            if(i + reverse(i) == num)
                return true;
        }
        return false;
    }
};