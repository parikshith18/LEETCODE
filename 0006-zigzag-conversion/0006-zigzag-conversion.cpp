class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        if(numRows == 1 || numRows >= n)
            return s;

        int row = 0, direction = 1;
        vector<string> rows(numRows);
        for(char ch: s){
            rows[row] += ch;
            if(row == 0)
                direction = 1;
            else if(row == numRows - 1)
                direction = -1;
            row += direction;
        }

        string ans = "";
        for(string x: rows)
            ans += x;
        return ans;
    }
};

// Time and Space - O(n)..