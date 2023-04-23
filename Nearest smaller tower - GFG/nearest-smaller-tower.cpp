//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    vector<int> nearestSmallerTower(vector<int> arr)
    {
        // code here
        stack<pair<int,int>> st;
        int n=arr.size();
        vector<int> ans(n,-1);
        
        
        for(int i=0;i<n;i++)
        {
            if(st.empty())
            {
                ans[i]=-1;
            }
            else if(st.top().first < arr[i])
            {
                ans[i]=st.top().second;
            }
            else
            {
                while(!st.empty() and st.top().first >= arr[i])
                {
                    st.pop();
                }
                if(st.empty())ans[i]=-1;
                else ans[i]=st.top().second;
            }
            st.push({arr[i],i});
        }
        
        // for(int i=0;i<n;i++)
        // {
        //     cout<<ans[i]<<" ";
        // }
        // cout<<endl;
        
        for(int i=n-1;i>=0;i--)
        {
            if(st.empty())
            {
                continue;
            }
            else if(st.top().first < arr[i])
            {
                if(ans[i]==-1)ans[i]=st.top().second;
                else if((i-ans[i]+1) > st.top().second-i+1)
                {
                   ans[i]=st.top().second;
                }
                else if((i-ans[i]+1) == st.top().second-i+1)
                {
                    int num=arr[ans[i]];
                    if(num > st.top().first)ans[i]=st.top().second;
                }
                
            }
            else
            {
                while(!st.empty() and st.top().first >= arr[i])
                {
                    st.pop();
                }
                if(st.empty())ans[i]=-1;
                else
                {
                    if(ans[i]==-1)ans[i]=st.top().second;
                    else if((i-ans[i]+1) > st.top().second-i+1)
                    {
                       ans[i]=st.top().second;
                    }
                    else if((i-ans[i]+1) == st.top().second-i+1)
                    {
                        int num=arr[ans[i]];
                        if(num > st.top().first)ans[i]=st.top().second;
                    }
                }
            }
            st.push({arr[i],i});
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution ob;
        vector<int> ans = ob.nearestSmallerTower(v);
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends