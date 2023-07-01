class Solution {
public:
    int ans=INT_MAX;
    void solve(int ind,vector<int>&arr, int k, vector<int> &bag)
    {        
        if(ind==arr.size())
        {
            int maxi=INT_MIN;
            for(int i=0;i<k;i++)
            {
                maxi=max(maxi,bag[i]);
            }
            ans=min(ans,maxi);
            return;
        }
  
        for(int i=0;i<k;i++)
        {
            bag[i]+=arr[ind];
            solve(ind+1,arr,k,bag);
            bag[i]-=arr[ind];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> bag(k,0);
        solve(0,cookies,k,bag);
        return ans;
    }
};