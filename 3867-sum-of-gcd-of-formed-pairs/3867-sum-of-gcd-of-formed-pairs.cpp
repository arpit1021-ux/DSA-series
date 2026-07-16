class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int mx=INT_MIN;
        vector<int> prefixgcd(nums.size());
        for(int i=0;i<nums.size();i++){
            mx=max(mx,nums[i]);
            prefixgcd[i]=gcd(nums[i],mx);
        }
        sort(prefixgcd.begin(),prefixgcd.end());
        int n=prefixgcd.size();
        long long sum=0;
        for(int i=0;i<n/2;i++){
            sum+=gcd(prefixgcd[i],prefixgcd[n-i-1]);
        }
        return sum;
    }
};