class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int left[n];
        int mini_left=INT_MAX;
        int profit_left=0;
        int maxi_right=INT_MIN;
        int profit_right=0;
        int right[n];
        int total[n];
        int ans=0;
        
        for(int i=0;i<n;i++){
            mini_left=min(mini_left,prices[i]);
            profit_left=max(profit_left,prices[i]-mini_left);
            left[i]=profit_left;
        }

        for(int i=n-1;i>=0;i--){
            maxi_right=max(maxi_right,prices[i]);
            profit_right=max(profit_right,maxi_right-prices[i]);
            right[i]=profit_right;
        }
        
        for(int i=0;i<n;i++){
            total[i]=left[i]+right[i];
            ans=max(ans,total[i]);
        }
        return ans;
    }
};