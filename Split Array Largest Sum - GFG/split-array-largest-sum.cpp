//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isValid(int mid, int *arr, int n, int k)
    {
        int sum=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i] > mid)return false;
            sum+=arr[i];
            
            if(sum > mid)
            {
                sum=arr[i];
                k--;
            }
            else if(sum==mid)
            {
                sum=0;
                k--;
            }
        }
        
        if(sum!=0)k--;
        
        if(k>=0)return true;
        return false;
    }
    int splitArray(int arr[] ,int N, int K) {
        // code here
        int maxi=-1;
        int sum=0;
        for(int i=0;i<N;i++)
        {
            sum+=arr[i];
            maxi=max(maxi,arr[i]);
        }
        
        int low=maxi,high=sum;
        int ans=0;
        
        while(low<=high)
        {
            int mid=low + (high-low)/2;
            
            if(isValid(mid,arr,N,K))
            {
                high=mid-1;
                ans=mid;
            }
            else low=mid+1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends