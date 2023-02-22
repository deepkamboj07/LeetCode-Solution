class Solution {
public:
    bool isValid(int w,vector<int>&arr,int k)
    {
       int limit = 1;
        int curr = 0;
        for(auto i:arr) {
            if (i > w) {
                return false;
            }
            if (i + curr > w) {
                curr = i;
                limit++;
                if (limit > k) {
                    return false;
                }
            } else {
                curr += i; 
            }
            
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum=0;
        int low=1e9;
        for(auto i: weights){
            low=min(i,low);
            sum+=i;
        }
        int high=sum;
        int ans=0;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(isValid(mid,weights,days))
            {
              //  cout<<mid<<endl;
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
    }
};