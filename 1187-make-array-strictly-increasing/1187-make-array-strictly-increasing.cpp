class Solution {
public:
    int find(vector<int>&arr, int x)
    {
        int low=0;
        int high=arr.size()-1;
        int ans=-1;
        
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(arr[mid]<=x)
            {
                low=mid+1;
            }
            else
            {
                ans=arr[mid];
                high=mid-1;
            }
        }
        
        return ans;
    }
    int solve(vector<int>& arr1, vector<int>& arr2, int ind, int prev, map<pair<int, int>, int> &mp)
    {
        if(ind==arr1.size())return 0;
        if (mp.count({ind, prev})) return mp[{ind, prev}];
        
        int x=INT_MAX;
        int y=INT_MAX;
        int z=INT_MAX;
        
        if(arr1[ind]<=prev)
        {
            int cur=find(arr2,prev);
            if(cur>prev)
            {
                x=solve(arr1,arr2,ind+1,cur,mp);
            }
            if(x!=INT_MAX)x++;
        }
        else
        {
            y=solve(arr1,arr2,ind+1,arr1[ind],mp);
            
            int cur=find(arr2,prev);
            if(cur>prev)
            {
                z=solve(arr1,arr2,ind+1,cur,mp);
            }
            if(z!=INT_MAX)z++;      
        }
        
        return mp[{ind,prev}]=min({x,y,z});
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        
        sort(arr2.begin(),arr2.end());
        map<pair<int, int>, int>mp;
        int ans=solve(arr1,arr2,0,-1,mp);
        return (ans==INT_MAX)?-1:ans;
    }
};