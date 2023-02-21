class Solution {
public:
    int findClosestNumber(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int low=0;
        int high=arr.size()-1;
        int ans=-1;
        int mini=1e9;
        while(low<=high)
        {

                if(mini >= abs(arr[low]-0))
                {
                    mini=abs(arr[low]-0);
                    ans=arr[low];
                    cout<<ans<<" ";
                }
                low++;
        }
        
        return ans;
    }
};