#include <iostream>
using namespace std;

class Solution {
public:
    int numberOfSteps (int num) {
        int ans = 0;
        while(num != 0){
            ans ++;
            (num % 2) ? (num -= 1):(num /= 2);
        }
        return ans;
    }
};