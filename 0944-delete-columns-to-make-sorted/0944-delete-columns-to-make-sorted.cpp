class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size();
        int m=strs[0].length(),count=0;
        
        for(int i=0;i<m;i++)
        {
            vector<char> v;
            for(int j=0;j<n;j++)
            {
                char ch=strs[j][i];
                if(v.empty())
                {
                    v.push_back(ch);
                }
                else
                {
                    if(v.back() > ch)
                    {
                        count++;
                        break;
                    }
                    else v.push_back(ch);
                }
            }
        }
        
        return count;
    }
};