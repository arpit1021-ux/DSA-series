class Solution {
public:
    int prod(int n){
        int product=1;
        while(n>0){
            int digit=n%10;
            product=digit*product;
            n=n/10;
        }
        return product;
    }
    int smallestNumber(int n, int t) {
        int ans=n;
        int mul=prod(ans);
        while(mul%t!=0){
            ans++;
            mul=prod(ans);
        }
        return ans;
    }
};