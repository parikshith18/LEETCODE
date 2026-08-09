class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int leftsum = 0, rightsum = 0;
        // first k cards
        for(int i = 0; i < k; i++){
            leftsum += cardPoints[i];
        }

        int rightindex = n - 1, maxsum = leftsum;
        // Replace Right cards with Left cards
        for(int i = k - 1; i >= 0; i--){
            leftsum -= cardPoints[i];
            rightsum += cardPoints[rightindex];
            rightindex--;
            maxsum = max(maxsum, leftsum + rightsum);
        }
        return maxsum;
    }
};