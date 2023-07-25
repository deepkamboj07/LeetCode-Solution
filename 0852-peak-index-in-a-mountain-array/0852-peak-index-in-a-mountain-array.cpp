class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low=0;
        int high=arr.size()-1;
        int ans=-1;
        while(low<=high)
        {
            int mid=low + (high-low)/2;
            cout<<mid<<endl;
            if(mid!=0 and mid!=arr.size()-1 and arr[mid]>arr[mid-1] and arr[mid]>arr[mid+1])
            {
                return mid;
            }
            else if(mid!=arr.size()-1 and  arr[mid] > arr[mid+1])
                high=mid-1;
            else low=mid+1;
        }
        
        return ans;
    }
};