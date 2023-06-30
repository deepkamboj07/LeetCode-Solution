class Solution {
public:
    int fun(string a, string b, int n, int m,char ch)
    {
        int t=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]<ch)t++;
        }
        for(int i=0;i<m;i++)
        {
            if(b[i]>=ch)t++;
        }
        
        return t;
    }
    int minCharacters(string a, string b) {
        int mini=1e9;
        int n=a.size();
        int m=b.size();
        
        for(int i=0;i<26;i++)
        {
            //condition 1
            int total=0;
            for(int j=0;j<n;j++)
            {
                if(a[j]!='a'+i)total++;
            }
            for(int j=0;j<m;j++)
            {
                if(b[j]!='a'+i)total++;
            }
            
            mini=min(mini,total);
        }
        
        for(int i=1;i<26;i++)
        {   
            //condition 2
            int total=0;
            total=fun(a,b,n,m,'a'+i);
            mini=min(mini,total);
            
            //condition 3
            total=fun(b,a,m,n,'a'+i);
            mini=min(mini,total);
        }
        
        return mini;
    }
};