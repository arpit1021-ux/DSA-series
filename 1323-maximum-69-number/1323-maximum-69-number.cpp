class Solution {
public:
    int maximum69Number (int num) {
        int dummy=num;
        string st=to_string(num);
        for(int i=0;i<st.size();i++){
            if(st[i]=='6'){
                st[i]='9';
                break;
            }
            // dummy=stoi(st);
        }
        dummy=stoi(st);
        return dummy;
    }
};