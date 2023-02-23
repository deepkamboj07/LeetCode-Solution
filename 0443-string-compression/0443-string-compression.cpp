class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        char prev=chars[0];
        int count=1;
        vector<char>tmp;
        for(int i=1;i<n;i++)
        {
            if(prev==chars[i])
            {
                count++;
            }
            else
            {
                if(count>1)
                {
                    tmp.push_back(prev);
                    string c=to_string(count);
                    for(auto it: c)
                    {
                        tmp.push_back(it);
                    }
                }
                else
                {
                    tmp.push_back(prev);
                }
                prev=chars[i];
                count=1;
            }
        }
        
        if(count>1)
        {
                tmp.push_back(prev);
                string c=to_string(count);
                for(auto it: c)
                {
                    tmp.push_back(it);
                }
        }
        else
        {
               tmp.push_back(prev);
        }
        
        int i=0;
        for(auto it: tmp)
        {
            chars[i++]=it;
        }
        return tmp.size();
    }
};