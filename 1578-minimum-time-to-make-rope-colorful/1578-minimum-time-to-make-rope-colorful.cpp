class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {

        int n = colors.size();
        int ans = 0;

        int i = 0;

        while (i < n) {

            int sum = 0;
            int maxi = 0;

            char currentColor = colors[i];

            // Traverse one group of same color
            while (i < n && colors[i] == currentColor) {

                sum += neededTime[i];
                maxi = max(maxi, neededTime[i]);

                i++;
            }

            // Remove all except the most expensive one
            ans += (sum - maxi);
        }

        return ans;
    }
};