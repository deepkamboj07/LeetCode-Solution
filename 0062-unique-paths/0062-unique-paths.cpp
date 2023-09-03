class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> pre(n,0);
        pre[0]=1;
        for(int i=0;i<m;i++)
        {
            vector<int> cur(n,0);
            for(int j=0;j<n;j++)
            {
                if(i==0 and j==0) cur[j]=1;
                else
                {
                    int right=0,down=0;
                    if(i>0)right=pre[j];
                    if(j>0)down=cur[j-1];
                    cur[j]=right+down;
                }
            }
            pre=cur;
        }
        return pre[n-1];
    }
};