class Solution {
public:
    int stoi(string inp){
        int ans = 0;
        int mark = 1;
        if(inp[0] == '-') mark = -1;
        else inp = '+' + inp;
        for(int i = 1; i < inp.size(); i ++){
            ans *= 10;
            ans += (inp[i] - '0');
        }
        return ans*mark;
    }
    int calPoints(vector<string>& ops) {
        int ans = 0;
        vector<int> nums;
        for(string op: ops){
            if(op == "+"){
                nums.push_back(nums[nums.size() - 1] + nums[nums.size() - 2]);
            }else if(op == "D"){
                nums.push_back(nums[nums.size() - 1] * 2);
            }else if(op == "C"){
                nums.pop_back();
            }else{
                nums.push_back(stoi(op));
            }
        }
        for(int n: nums) ans += n;
        return ans;
    }
};
