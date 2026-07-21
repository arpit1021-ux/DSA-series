class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>freq;
        for(auto c:s){
            freq[c]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto it:freq){
            pq.push({it.second,it.first});
        }
        string ans="";
        while(!pq.empty()){
            ans+=string(pq.top().first,pq.top().second);
            pq.pop();
        }
        return ans;
    }
};