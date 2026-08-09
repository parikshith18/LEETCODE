class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0, maxi = 0, n = fruits.size();
        int k = 2; // 2 fruits here..
        unordered_map <int,int> mp;
        for(int right = 0; right < n; right++){
            mp[fruits[right]]++;
            if(mp.size() > k){
                mp[fruits[left]]--;
                if(mp[fruits[left]] == 0)
                    mp.erase(fruits[left]);
                left++;
            }

            if(mp.size() <= k)
                maxi = max(maxi, right - left + 1);
        }
        return maxi;
    }
};