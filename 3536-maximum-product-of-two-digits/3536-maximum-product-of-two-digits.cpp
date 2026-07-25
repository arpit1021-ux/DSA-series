class Solution {
public:
    int maxProduct(int n) {
        vector<int>digits;
        while(n>0){
            int digit=n%10;
            digits.push_back(digit);
            n=n/10;
        }
        sort(rbegin(digits),rend(digits));
        return digits[0]*digits[1];
    }
};