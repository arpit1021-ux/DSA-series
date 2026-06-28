class Solution {
public:
    //fact 1=operations=parts-1
    //fact 2=a number should be broken such that saath vaalo ko todene me kmm operations lge----->parts=nums[i]/nums[i+1]----->if(not divisible) parts++;
    //fact 3=peeche se traverse krenge bcz agr aage se krenge thenn ek baar aage chle gye we need to comeback again to previous ones.
    long long minimumReplacement(vector<int>& nums) {
        long long operations=0;
        int n=nums.size();
        int parts=0;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<=nums[i+1]){
                continue;
            }
            parts=nums[i]/nums[i+1];
            if(nums[i]%nums[i+1]!=0){
                parts++;
            }
            operations+=parts-1;
            nums[i]/=parts;
        }
        return operations;
    }
};