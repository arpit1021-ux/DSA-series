class Solution {
public:
    int toseconds(int h,int m,int s){
        return h*3600+m*60+s;
    }
    int secondsBetweenTimes(string startTime, string endTime) {
        int h1=startTime[0]*10+startTime[1];
        int m1=startTime[3]*10+startTime[4];
        int s1=startTime[6]*10+startTime[7];
        int h2=endTime[0]*10+endTime[1];
        int m2=endTime[3]*10+endTime[4];
        int s2=endTime[6]*10+endTime[7];
        int t1=toseconds(h1,m1,s1);
        int t2=toseconds(h2,m2,s2);
        return t2-t1;
    }
};