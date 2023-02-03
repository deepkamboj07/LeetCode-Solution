class Solution {
public:
    
    //Observe Again please...
    
    long long putMarbles(vector<int>& weights, int k) {
        int n=weights.size();
        vector<int> sum;
        for(int i=0;i<n-1;i++)
        {
            sum.push_back(weights[i] + weights[i+1]);
        }
        
        sort(sum.begin(),sum.end());
        long long int maxi=0,mini=0;
        n=sum.size();
        for(int i=0;i<(k-1);i++)
        {
            maxi+=sum[i];
            mini+=sum[n-i-1];
        }
        return (mini - maxi);
    }
};