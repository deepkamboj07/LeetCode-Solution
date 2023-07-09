class Solution {
    int helper(string& s, char a, char b){
        int ans = 0, cur = 0;
        bool flag = false, secFlag = false;
        for(int i=0; i<s.size(); i++){
            if (s[i] == b){
                flag = true;
                secFlag = true;
            }
            cur += s[i] == a ? 1 : s[i] == b ? -1 : 0;
            if (cur < 0){
                cur = 0;
                flag = false;
            }
            if (flag){
                ans = max(ans, cur);
            }
        }
        if (secFlag){
            ans = max(ans, cur-1);
        }
        return ans;
    }
public:
    int largestVariance(string s) {
        unordered_set<char> unique;
        for(char ch: s){
            unique.insert(ch);
        }
        int ans = 0;
        vector<char> uni(unique.begin(), unique.end());
        for(int i=0; i<uni.size(); i++){
            for(int j=i+1; j<uni.size(); j++){
                int op1 = helper(s, uni[i], uni[j]);
                int op2 = helper(s, uni[j], uni[i]);
                ans = max(ans, max(op1, op2));
            }
        }
        return ans;
    }
};