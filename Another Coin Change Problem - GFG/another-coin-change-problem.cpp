//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    bool solve(int ind, vector<int> &coins, int n, int k,int sum,int target, vector<vector<vector<int>>> &dp)
    {
        if(sum > target) return false;
        if(k<0) return false;
        
        if(dp[ind][k][sum]!=-1)return dp[ind][k][sum];
        if(ind==n)
        {
            if(sum==target and k==0)return true;
            return false;
        }
        
        bool take=solve(ind,coins,n,k-1,coins[ind]+sum,target,dp);
        
        bool noTake=solve(ind+1,coins,n,k,sum,target,dp);
        
        return dp[ind][k][sum]=(take || noTake);
        
    }
    bool makeChanges(int N, int K, int target, vector<int> &coins) {
        // code here
        
        vector<vector<vector<int>>> dp(N+1,vector<vector<int>>(K+1,vector<int>(target+1e1,-1)));
        return solve(0,coins,N,K,0,target,dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int N;
        scanf("%d", &N);

        int K;
        scanf("%d", &K);

        int target;
        scanf("%d", &target);

        vector<int> coins(N);
        Array::input(coins, N);

        Solution obj;
        bool res = obj.makeChanges(N, K, target, coins);

        cout << res << endl;
    }
}

// } Driver Code Ends