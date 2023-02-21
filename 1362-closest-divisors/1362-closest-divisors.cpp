class Solution {
public:
    vector<int> solve(int num)
    {
        vector<int> ans(2,-1);
        int mini=1e9;
        int n=num/2;
        for(int i=1;i<=sqrt(num);i++)
        {
            if(num%i==0)
            {
                int a=i;
                int b=num/i;
                int diff=abs(a-b);
                if(mini > diff)
                {
                    mini=diff;
                    ans[0]=a;
                    ans[1]=b;
                }
            }
        }
        return ans;
    }
    vector<int> closestDivisors(int num) {
              
        vector<int> a=solve(num+1);
        vector<int> b=solve(num+2);
        if(a[0]==-1 and a[1]==-1)return b;
        if(b[0]==-1 and b[1]==-1)return a;
        
        if(abs(a[0] - a[1]) < abs(b[0]- b[1]))return a;
        return b;
    }
};