#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> ans;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == c)ans.push_back(0);
            else ans.push_back(s.size());
        }

        int now ;
        now = s.size();
        for(int i = 0; i < s.size(); i ++){
            if(ans[i] == 0) now = 0;
            ans[i] = min(ans[i], now);
            now ++;
        }
        now = s.size();
        for(int i = s.size() -1 ; i>= 0; i--){
            if(ans[i] == 0) now = 0;
            ans[i] = min(ans[i], now);
            now ++;
        }
        return ans;
    }
};