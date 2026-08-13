class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1); // Everyone gets atleast 1 candies
        
        // Left -> Right
        for(int i = 1; i < n; i++){
            if(ratings[i] > ratings[i - 1])
                candies[i] = candies[i - 1] + 1;
        }

        // Right -> Left
        for(int i = n - 2; i >= 0; i--){
            if(ratings[i] > ratings[i + 1])
                candies[i] = max(candies[i], candies[i + 1] + 1);
                // Satisfy condition .. if already left has given candies 
                // Right no need to give as we finding minimum candies
        }

        // Count Candies
        int total = 0;
        for(int candy: candies)
            total += candy;
        return total;
    }
};