class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int left = 0, n = s.size(), ones = 0;
        string ans = "";

        for(int right = 0; right < n; right++) {

            if(s[right] == '1')
                ones++;

            // if ones exceed k
            while(ones > k) {
                if(s[left] == '1')
                    ones--;
                left++;
            }

            // remove unnecessary 0s
            while(ones == k && s[left] == '0')
                left++;

            if(ones == k) {
                string curr = s.substr(left, right - left + 1);

                if(ans == "" || curr.size() < ans.size() ||
                   (curr.size() == ans.size() && curr < ans))
                    ans = curr;
            }
        }
        return ans;
    }
};