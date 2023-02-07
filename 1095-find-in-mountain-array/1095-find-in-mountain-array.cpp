/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findPeak(MountainArray &arr)
    {
        int low=0,high=arr.length()-1;
        int n=arr.length();
        while(low<=high)
        {
            int mid=(low+high)>>1;
            if(mid!=0 and mid!=(n-1) and arr.get(mid)>arr.get(mid+1) and arr.get(mid)>arr.get(mid-1))
                return mid;
            if(mid==(n-1) or arr.get(mid)<arr.get(mid+1))
                low=mid+1;
            else high=mid-1;
        }
        return -1;
    }
    int findTarget(int low,int high,MountainArray &arr,int key)
    {
        while(low<=high)
        {
            int mid=(low+high)>>1;
            int data=arr.get(mid);
            if(data==key)return mid;
            if(data > key)
                high=mid-1;
            else low=mid+1;
        }
        return 1e9;
    }
    int findTarget2(int low,int high,MountainArray &arr,int key)
    {
        while(low<=high)
        {
            int mid=(low+high)>>1;
            int data=arr.get(mid);
            if(data==key)return mid;
            if(data < key)
                high=mid-1;
            else low=mid+1;
        }
        return 1e9;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int mid=findPeak(mountainArr);
        int n=mountainArr.length();
       // cout<<mid;
        int ans=1e9;
        ans=min(findTarget(0,mid,mountainArr,target), findTarget2(mid+1,(n-1),mountainArr,target));
        
        return (ans==1e9)?-1:ans;
    }
};