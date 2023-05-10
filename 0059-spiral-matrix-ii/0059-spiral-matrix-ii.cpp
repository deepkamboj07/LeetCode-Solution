class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n));
        vector<int> num;
        
        if(n==1)
        {
            ans[0][0]=1;
            return ans;
        }
        for(int i=1;i<=n*n;i++)
            num.push_back(i);
        
        
        int sr=0,er=n-1;
        int sc=0,ec=n-1;
        
        int k=0;
        int size=n*n;
        
        for(int i=0;i<size;i++)
            cout<<num[i]<<" ";
      
        while(sr<=er and sc<=ec)
        {
            for(int i=sc;i<=ec;i++)
                ans[sr][i]=num[k++];
            
            sr++;
            if(k==size)
                break;
            for(int i=sr;i<=er;i++)
                ans[i][ec]=num[k++];
            ec--;
            if(k==size)
                break;
            for(int i=ec;i>=sc;i--)
                ans[er][i]=num[k++];
            er--;
            if(k==size)
                break;            
            for(int i=er;i>=sr;i--)
                ans[i][sc]=num[k++];
            sc++;
            if(k==size)
                break;            
        }
        
        return ans;
    }
};