class Solution {
public:
    int maximumLengthSubstring(string s) {
        int left=0;
        int right=0;
        int ans=0;
        int freq[26]={0};
        while(right<s.size()){
            char ch=s[right];
            freq[ch-'a']++;
            while(freq[ch-'a']>2){
                freq[s[left]-'a']--;
                left++;
            }
            right++;
            ans=max(ans,right-left);
        }
        return ans;
    }
};