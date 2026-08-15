class Solution {
public:
    double average(vector<int>& salary) {
        int n = salary.size();
        double sum = salary[0], maxi = salary[0], mini = salary[0];
        for(int i = 1; i < n; i++){
            if(salary[i] > maxi)
                maxi = salary[i];
            if(salary[i] < mini)
                mini = salary[i];
            sum += salary[i];
        }
        return (sum - maxi - mini)/ (n - 2);
    }
};