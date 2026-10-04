class Solution {
public:

    vector<vector<int>> dp;

    bool solve(int i, int open, string &s) {

        if(open < 0)
            return false;

        if(i == s.size())
            return open == 0;

        // Already calculated?
        if(dp[i][open] != -1)
            return dp[i][open];

        bool isValid = false;

        if(s[i] == '(') {

            isValid = solve(i + 1, open + 1, s);

        }
        else if(s[i] == ')') {

            if(open > 0)
                isValid = solve(i + 1, open - 1, s);

        }
        else { // '*'

            // '*' as ')'
            if(open > 0)
                isValid |= solve(i + 1, open - 1, s);

            // '*' as '('
            isValid |= solve(i + 1, open + 1, s);

            // '*' as empty
            isValid |= solve(i + 1, open, s);
        }

        // Remember the answer
        return dp[i][open] = isValid;
    }

    bool checkValidString(string s) {

        int n = s.size();

        dp.assign(n, vector<int>(n + 1, -1));

        return solve(0, 0, s);
    }
};