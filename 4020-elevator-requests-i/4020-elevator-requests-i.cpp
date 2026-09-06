class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int m=requests.size();
        int ans=requests[0];
        for(int i=1;i<m;i++){
            ans+=abs(requests[i]-requests[i-1]);
        }
        return ans;
    }
};