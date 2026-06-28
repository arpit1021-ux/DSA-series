class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int>startEnd(n+1,0);
        for(int i=0;i<=n;i++){
            int s=max(0,i-ranges[i]);
            int e=min(n,i+ranges[i]);
            startEnd[s]=max(startEnd[s],e);
        }
        int taps=0;
        int maxEnd=0;
        int currEnd=0;
        for(int i=0;i<=n;i++){
            if(i>maxEnd) return -1;
            if(i>currEnd){
                taps++;
                currEnd=maxEnd;
            }
            maxEnd=max(maxEnd,startEnd[i]);
        }
        return taps;
    }
};