class Solution {
public:
    bool winnerOfGame(string colors) {
        int n=colors.length();
        int a=0;
        int b=0;
        if(n<=2){
            return false;
        }
        for(int i=0;i<n;i++){
            if(i>0 && i<n-1){
                if(colors[i-1]=='A' && colors[i]=='A' && colors[i+1]=='A'){
                a++;
            }
            if(colors[i-1]=='B' && colors[i]=='B' && colors[i+1]=='B'){
                b++;
            }
            }
            
        }
        return a>b;
    }
};