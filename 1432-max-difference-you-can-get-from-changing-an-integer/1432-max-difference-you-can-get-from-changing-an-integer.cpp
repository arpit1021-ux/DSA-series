class Solution {
public:
    int maxDiff(int num) {
        string s1=to_string(num);
        string s2=s1;
        char changeto9=' ';
        for(char c:s1){
            if(c!='9'){
                changeto9=c;
                break;
            }
        }
        if(changeto9!=' '){
            for(int i=0;i<s1.size();i++){
                if(s1[i]==changeto9){
                    s1[i]='9';
                }
            }
        }
        char changeToSmall=' ';
        if(s2[0]!='1'){
            changeToSmall=s2[0];
            for (int i = 0; i < s2.size(); i++) {
                if (s2[i] == changeToSmall) {
                    s2[i] = '1';
                }
            }
        }
        else{
            for (int i = 1; i < s2.size(); i++) {
                if (s2[i] != '0' && s2[i] != '1') {
                    changeToSmall = s2[i];
                    break;
                }
            }

            // Change that digit to 0
            if (changeToSmall != ' ') {
                for (int i = 1; i < s2.size(); i++) {
                    if (s2[i] == changeToSmall) {
                        s2[i] = '0';
                    }
                }
            }
        }
        int maximum = stoi(s1);
        int minimum = stoi(s2);

        return maximum - minimum;
    }
};