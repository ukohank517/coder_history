class Solution {
public:
    int brokenCalc(int X, int Y) {
        int ans = 0;
        while(X < Y){
            X *= 2;
            ans ++;
        }

        int rest = (X - Y);
        int base = pow(2, ans);
        while(base != 0){
            while(rest >= base){
                ans += 1;
                rest -= base;
            }
            base /= 2;
        }

        return ans + rest;
    }
};