class Solution {
public:
    // if xor of entire array != 0 then return n
    // if xor=0 then 
    // 1----if hasNonZero ans=n-1
    // 2----if no any non zero then ans=0;
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int total=0;
        bool hasNonZero=false;
        for(int x : nums){
            total^=x;
            if(x!=0) hasNonZero=true;
        }
        if(total!=0) return n;
        if(hasNonZero) return n-1;
        return 0;
    }
};