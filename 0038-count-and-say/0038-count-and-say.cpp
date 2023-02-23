class Solution
{
    public:
        string countAndSay(int n) {
            if(n==1)return "1";
            string res="1#";
            n--;
            while(n--)
            {
                int m=res.size();
                int count=0;
                char prev='#';
                string tmp="";
                
                for(int i=0;i<m;i++)
                {
                    if(res[i]==prev)
                    {
                        count++;
                    }
                    else
                    {
                        if(prev!='#')
                        {
                            tmp+=to_string(count);
                            tmp+=prev;
                        }
                        prev=res[i];
                        count=1;
                    }
                }
                res=tmp;
                res+="#";
            }
            
            res.pop_back();
            return res;
        }
};