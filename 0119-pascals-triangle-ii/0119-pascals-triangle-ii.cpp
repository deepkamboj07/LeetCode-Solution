class Solution {
public:
    vector<int> getRow(int n) {
        n++;
        if(n==1)return {1};
        vector<vector<int>> ans;
        ans.push_back({1});
        for(int i=1;i<n;i++)
        {
            int start=1;
            int end=1;
            vector<int> temp(i+1);
            temp[0]=start;
            temp[i]=end;
            
            for(int j=1;j<(i);j++)
            {
                int sum=ans[i-1][j-1]+ans[i-1][j];
                temp[j]=sum;
            }
            ans.push_back(temp);
        }
        
        for(auto it: ans)
        {
            for(auto i:it)
                cout<<i<<" ";
            cout<<endl;
        }
        
        return ans[n-1];
        
    }
};