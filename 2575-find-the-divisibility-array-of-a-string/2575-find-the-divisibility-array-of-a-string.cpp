class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int> ans;
        string tmp="";
        long long rem=0;
        for(auto d: word)
        {
            int digit=d-'0';
            int plus=(digit%m);
            rem=(rem*10+plus)%m;
            if(rem==0)
            {
                ans.push_back(1);
            }
            else ans.push_back(0);
            //cout<<rem<<" ";    
        }
        return ans;
    }
};