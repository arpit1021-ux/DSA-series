class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n=piles.size();
        sort(piles.begin(),piles.end());
        int slargest=0;
        int alice=n-1;
        int me=n-2;
        int bob=0;
        while(bob<me){
            slargest+=piles[me];
            alice-=2;
            me-=2;
            bob++;
        }
        return slargest;
    }
};