class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(), prices.end());
        sort(discounts.begin(), discounts.end());

        double ans = 0;

        int i = prices.size() - 1;
        int j = discounts.size() - 1;

        // Apply largest discounts to largest prices
        while (i >= 0 && j >= 0) {
            ans += (double)prices[i] * (100 - discounts[j]) / 100.0;
            i--;
            j--;
        }

        // Remaining prices have no discount
        while (i >= 0) {
            ans += prices[i];
            i--;
        }

        return ans;
    }
};