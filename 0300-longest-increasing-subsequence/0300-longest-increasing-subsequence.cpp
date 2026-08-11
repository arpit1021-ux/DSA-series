class Solution {
public:
    // Binsary search approach
    int lengthOfLIS(vector<int>& nums) {
        vector<int>temp; //for temporarily storing subsequence
        temp.push_back(nums[0]);
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>temp.back()){
                temp.push_back(nums[i]);
            }
            else{
                int ind=lower_bound(temp.begin(),temp.end(),nums[i]) - temp.begin(); // gives index of nums[i] or first index where greater than nums[i]
                temp[ind]=nums[i]; 
            }
        }
        return temp.size();
    }
};