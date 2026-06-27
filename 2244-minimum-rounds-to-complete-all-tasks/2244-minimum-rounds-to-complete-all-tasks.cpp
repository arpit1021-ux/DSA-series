class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        sort(tasks.begin(),tasks.end());
        int rounds=0;
        unordered_map<int,int>mp;
        int n=tasks.size();
        for(int i=0;i<n;i++){
            mp[tasks[i]]++;
        }
        for(auto it : mp){
            int count=it.second;
            if(count==1){
                return -1;
            }
            else if(count%3==0){
                rounds+=count/3;
            }
            else{
                rounds+=count/3+1;
            }
        }
        return rounds;
    }
};