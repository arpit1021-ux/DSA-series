class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        long long sum1=0;
        long long sum2=0;
        int cnt1=0;
        int cnt2=0;
        for(int i=0;i<n;i++){
            sum1+=nums1[i];
            if(nums1[i]==0){
                cnt1++;
            }
        }
        for(int i=0;i<m;i++){
            sum2+=nums2[i];
            if(nums2[i]==0){
                cnt2++;
            }
        }
        long long minsum1=sum1+cnt1;
        long long minsum2=sum2+cnt2;
        if (minsum1 == minsum2) {
            return minsum1;
        }
        if(minsum1<minsum2){
            if(cnt1==0) return -1;
            return minsum2;
        }
        if(cnt2==0) return -1;
        return minsum1;
    }   
};