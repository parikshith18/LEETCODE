class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, maxfreq = 0, maxi = 0;
        int n = s.size();
        vector <int> freq(26, 0);
        for(int right = 0; right < n; right++){
            freq[s[right] - 'A']++;
            maxfreq = max(maxfreq, freq[s[right] - 'A']);
            while((right- left + 1) - maxfreq > k){
                freq[s[left] - 'A']--;
                left++;
            }
            maxi = max(maxi, right - left + 1);
        }
        return maxi;
    }
};