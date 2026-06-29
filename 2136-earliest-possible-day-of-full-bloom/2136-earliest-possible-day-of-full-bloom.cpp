class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n=plantTime.size();
        vector<pair<int,int>>vec(n);
        for(int i=0;i<n;i++){
            vec[i]={plantTime[i],growTime[i]};
        }
        auto lambda=[](pair<int,int>&p1,pair<int,int>p2){
            return p1.second>p2.second;
        };
        sort(vec.begin(),vec.end(),lambda);
        int totalPlantDays = 0;   // Total planting days spent so far
        int answer = 0;           // Latest bloom day

        for (int i = 0; i < n; i++) {

            int currPlant = vec[i].first;
            int currGrow = vec[i].second;

            // Plant current flower
            totalPlantDays += currPlant;

            // Day on which this flower blooms
            int bloomDay = totalPlantDays + currGrow;

            // Update answer
            answer = max(answer, bloomDay);
        }

        return answer;
    }
};