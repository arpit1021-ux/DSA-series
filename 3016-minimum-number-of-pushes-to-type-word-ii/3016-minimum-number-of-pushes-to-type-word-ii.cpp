class Solution {
public:
    int minimumPushes(string word) {
        vector<int>arr(26,0);
        int res=0;
        for(char &ch:word){
            arr[ch-'a']++;
        }
        sort(begin(arr),end(arr),greater<int>());
        for(int i=0;i<arr.size();i++){
            int freq=arr[i];
            int press=i/8+1;
            res+=freq*press;
        }
        return res;
    }
};