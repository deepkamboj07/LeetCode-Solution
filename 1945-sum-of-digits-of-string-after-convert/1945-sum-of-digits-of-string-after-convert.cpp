class Solution {
public:
    
    int digitSum(int n)
    {
        int ans=0;
        while(n)
        {
            int d=n%10;;
            ans+=d;
            n/=10;
        }
        return ans;
    }
    int getLucky(string s, int k) {
        
        int d=0;
        for(int i=(s.size()-1);i>=0;i--)
        {
            int m=s[i]-'a'+1;
           // cout<<m<<endl;
            if(m < 10)
            {
                d+=(m);
            }
            else
            {
                while(m)
                {
                    int l=m%10;
                    d=d+l;
                    m/=10;
                }
            }
        }
        
      //  cout<<d;
        k--;
         
        while(k--)
        {
            d=digitSum(d);
        }
        
        return d;
    }
};