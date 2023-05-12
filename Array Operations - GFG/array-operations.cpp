//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int arrayOperations(int n, vector<int> &arr) {
        // code here
        int zero=0;
        int ans=0;
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==0)
            {
                zero++;
                if(c>0)ans++;
                c=0;
            }
            else c++;
        }
        
        if(zero==n)return 0;
        if(ans==0)return -1;
        else return (arr[n-1]==0)?ans:ans+1;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        
        
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution obj;
        int res = obj.arrayOperations(n, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends