class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low=0;
        int high=arr.size()-1;
        int n=arr.size();
        while(low<=high)
        {
            int mid=(low+high)/2;
            cout<<mid<<" ";
            if(mid!=n-1 and mid!=0 and arr[mid] > arr[mid-1] and arr[mid] > arr[mid+1])
                return mid;
            
            if(mid==(n-1) || arr[mid] < arr[mid+1])
                low=mid+1;
            else
                high=mid-1;
            
        }
        return -1;
    }
};