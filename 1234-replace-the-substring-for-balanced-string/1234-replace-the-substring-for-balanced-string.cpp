class Solution {
public:
    int balancedString(string s) {
        int n = s.size(), need = n / 4;
        int count[26] = {0};

        // Count all characters
        for(char c : s)
            count[c - 'A']++;

        // Already balanced
        if(count['Q' - 'A'] == need &&
           count['W' - 'A'] == need &&
           count['E' - 'A'] == need &&
           count['R' - 'A'] == need)
            return 0;

        int left = 0, ans = n;

        for(int right = 0; right < n; right++) {

            // Put right inside the replacement window
            count[s[right] - 'A']--;

            while(left <= right &&
                  count['Q' - 'A'] <= need &&
                  count['W' - 'A'] <= need &&
                  count['E' - 'A'] <= need &&
                  count['R' - 'A'] <= need) {

                ans = min(ans, right - left + 1);

                // Remove left from window → put it back outside
                count[s[left] - 'A']++;
                left++;
            }
        }

        return ans;
    }
};