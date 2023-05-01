class Solution {
public:
    double average(vector<int>& salary) {
        double sum=0,n=salary.size();
        int mini=1e9;
        int maxi=-1;
        
        for(int i=0;i<n;i++)
        {
            sum+=salary[i];
            mini=min(mini,salary[i]);
            maxi=max(maxi,salary[i]);
        }
        
        return ((sum)-(mini+maxi))/(double)(n-2);
    }
};