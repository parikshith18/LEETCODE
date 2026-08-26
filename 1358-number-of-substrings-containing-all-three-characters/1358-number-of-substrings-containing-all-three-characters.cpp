class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size(), left = 0, ans = 0;
        int count[3] = {0};
        for(int right = 0; right < n; right++){
            count[s[right] - 'a']++;
            while(count[0] && count[1] && count[2]){
                count[s[left] - 'a']--;
                left++;
            }
            ans += left;
        }
        return ans;
    }
};