class Solution {
public:
    vector<string>generateString(int n){
        vector<string>ans;
        //base case 
        if(n==1){
            return {"0","1"};
        }
        vector<string>temp=generateString(n-1);
        for(int i=0;i<temp.size();i++){
            // here we donot need to check whether string will start from 0 or 1 as it always start with 0
            ans.push_back("0"+temp[i]);
        }
        for(int i=temp.size()-1;i>=0;i--){
            // now from the reverse we need to append 1 in the starting 
            ans.push_back("1"+temp[i]);
        }
        return ans;
    }
    vector<int> grayCode(int n) {
        vector<string>grayString=generateString(n);
        vector<int>ans;
        for(auto it:grayString){
            ans.push_back(stoi(it,0,2));
        }
        return ans;

    }
};