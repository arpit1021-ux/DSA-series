class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>hash;
        int ans=0;
        int left=0;
        for(int right=0;right<s.size();right++){
            if(hash.find(s[right])!=hash.end() && hash[s[right]]>=left){
                left=hash[s[right]]+1;
            }
            hash[s[right]]=right;
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};