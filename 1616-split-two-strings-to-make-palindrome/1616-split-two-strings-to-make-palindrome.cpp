class Solution {
public:
    bool isPalindrome(string &s, int i, int j){
        while(i < j){
            if(s[i] != s[j])
                return false;
            i++, j--;
        }
        return true;
    }

    bool check(string &a, string &b){
        int i = 0, j = a.size() - 1;
        while(i < j && a[i] == b[j]){
            i++, j--;
        }
        return isPalindrome(a, i, j) || isPalindrome(b, i, j);
    }

    bool checkPalindromeFormation(string a, string b) {
        return check(a, b) || check(b, a);
    }
};

// Time Complexity: O(N). We perform at most a linear number of comparisons across the two orientations.
// Auxiliary Space: O(1). We only use pointers and variables; no extra strings are constructed.

// Step 1: Take two pointers i and j.
// i starts at the beginning, j starts at the end.

// Step 2: Compare characters from opposite ends
// of string a and string b.

// Step 3: If characters match, move both pointers
// inward (i++, j--).

// Step 4: When a mismatch occurs, we have two choices:
//   a) Check whether the remaining middle part of a is a palindrome.
//   b) Check whether the remaining middle part of b is a palindrome.

// Step 5: If either middle part is a palindrome,
// the current combination is valid.

// Step 6: Repeat the same process in reverse:
// check prefix of b + suffix of a.

// Step 7: If either combination forms a palindrome,
// return TRUE; otherwise return FALSE.