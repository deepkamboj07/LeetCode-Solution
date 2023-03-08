class Solution {
public:
    bool valid(vector<int> arr, int h, int k)
    {
        int hr=0;
        for(auto x:arr)
        {
            if(x%k==0)
                hr+=x/k;
            else hr+=(x/k)+1;
            if(hr>h)return false;
        }
        if(hr<=h)return true;
        return false;      
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int high=piles[0];
        
        for(auto b:piles)
            high=max(high,b);
        int low=1;
        int ans;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(valid(piles,h,mid))
            {
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
        
    }
};