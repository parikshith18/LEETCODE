class Solution {
public:
    int getsum(int n){
        int sum = 0;
        while(n > 0){
            int digit = n % 10;
            sum += digit * digit;
            n = n/10;
        }
        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> st;
        while(n != 1){
            if(st.count(n))
                return false;
            st.insert(n);
            n = getsum(n);
        }
        return true;
    }
};

// Time Complexity: O(log n) — Logarithmic time, because each digit-square calculation processes the digits of the number.
// Space Complexity: O(k) — Linear space, where k is the number of distinct numbers stored in the unordered_set.