class Solution {
public:
    void solve(int ind, int n, vector<vector<int>>& requests, vector<int>&ds,int count,int &ans)
    {
        if(ind==requests.size())
        {
            for(int i=0;i<ds.size();i++)
            {
                if(ds[i]!=0)return;
            }
            ans=max(ans,count);
            return;
        }
        
        ds[requests[ind][0]]--;
        ds[requests[ind][1]]++;
        solve(ind+1,n,requests,ds,count+1,ans);
        
        ds[requests[ind][0]]++;
        ds[requests[ind][1]]--;
        solve(ind+1,n,requests,ds,count,ans);
        
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        
        vector<int> ind(n,0);
        int ans=0;
        solve(0,n,requests,ind,0,ans);
        return ans;
    }
};