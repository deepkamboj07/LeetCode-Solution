class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string,int> mp;
        
        for(auto str: cpdomains)
        {   
            string digit="";
            int i=0;
            for(i=0;i<str.size();i++)
            {
                char ch=str[i];
                if(ch==' ')
                {
                    break;
                }
                else digit+=ch;
            }
            
            int dig=stoi(digit);
            string tmp="";
            for(int j=str.size();j>=i-1;j--)
            {
                if(str[j]=='.' || str[j]==' ')
                {
                    mp[tmp]+=dig;
                    tmp=str[j]+tmp;
                }
                else
                {
                    tmp=str[j]+tmp;
                }
            }

        }
        
        vector<string> ans;
        for(auto it: mp)
        {
            string tmp=to_string(it.second)+ " "+it.first;
            ans.push_back(tmp);
        }
        
        return ans;
    }
};