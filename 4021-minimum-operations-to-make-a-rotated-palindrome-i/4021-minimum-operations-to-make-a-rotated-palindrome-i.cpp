class Solution {
public:
    int charCost(char a, char b) {
        int x = (a - b + 26) % 26;
        int y = (b - a + 26) % 26;

        return min(x, y);
    }

    int minOperations(string s) {
        int n = s.size();
        int ans = INT_MAX;

        // Try every possible number of left rotations
        for (int k = 0; k < n; k++) {

            int cost = k;  // Cost of k rotations

            // Check every palindrome pair
            for (int i = 0; i < n / 2; i++) {

                int leftIndex = (k + i) % n;
                int rightIndex = (k + n - 1 - i) % n;

                cost += charCost(s[leftIndex], s[rightIndex]);
            }

            ans = min(ans, cost);
        }

        return ans;
    }
};