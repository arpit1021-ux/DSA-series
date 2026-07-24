class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXX = 2048;

        vector<vector<bool>> dp(4, vector<bool>(MAXX, false));
        dp[0][0] = true;

        for (int v : nums) {
            auto old = dp;
            auto nxt = dp;

            for (int cnt = 0; cnt <= 3; cnt++) {
                for (int x = 0; x < MAXX; x++) {
                    if (!old[cnt][x]) continue;

                    // Take this index once
                    if (cnt + 1 <= 3)
                        nxt[cnt + 1][x ^ v] = true;

                    // Take this index twice
                    if (cnt + 2 <= 3)
                        nxt[cnt + 2][x] = true;

                    // Take this index three times
                    if (cnt + 3 <= 3)
                        nxt[cnt + 3][x ^ v] = true;
                }
            }

            dp = move(nxt);
        }

        int ans = 0;
        for (bool ok : dp[3])
            if (ok) ans++;

        return ans;
    }
};