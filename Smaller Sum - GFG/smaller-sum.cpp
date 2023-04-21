//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
        // Code here
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
        {
            v.push_back({arr[i],i});
        }
        sort(v.begin(),v.end());
        vector<long long> sum(n,0),ans(n);
        int repeat=1,i=0;
        while(i<(n-1) and v[i].first==v[i+1].first)
        {
            i++;
            repeat++;
            sum[i]=0;
        }
        i++;
        for(i=i;i<n;i++)
        {
            sum[i]=(sum[i-1]+v[i-1].first);
            if(repeat >1)
            {
                sum[i]+=v[i-1].first*(repeat-1);
                repeat=1;
            }
          //  cout<<sum[i]<<" ";
            while(i<(n-1) and v[i].first==v[i+1].first)
            {
                i++;
                repeat++;
                sum[i]=sum[i-1];
               // cout<<sum[i]<<" ";
            }
        }
      //  cout<<endl;
        for(int i=0;i<n;i++)
        {
            ans[v[i].second]=sum[i];
        }
        
        return ans;
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
        Solution ob; 
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends