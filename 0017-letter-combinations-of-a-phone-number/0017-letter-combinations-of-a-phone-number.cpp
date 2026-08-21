class Solution {
public:

    vector<string> result;

    void solve(int idx, string &digits, string &temp,
               unordered_map<char, string> &mp) {

        // Base case: all digits processed
        if (idx >= digits.length()) {
            result.push_back(temp);
            return;
        }

        // Current digit
        char ch = digits[idx];

        // Get corresponding letters
        string str = mp[ch];

        // Try every possible letter
        for (int i = 0; i < str.length(); i++) {

            // Choose
            temp.push_back(str[i]);

            // Explore
            solve(idx + 1, digits, temp, mp);

            // Undo
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        if (digits.length() == 0)
            return {};

        unordered_map<char, string> mp = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        string temp = "";

        solve(0, digits, temp, mp);

        return result;
    }
};