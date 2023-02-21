class Solution {
public:

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        int i=0;
        int j=arr.size()-1;
        int s=k;
        while(j-i>=k)
        {
            if(abs(arr[i]-x) > abs(arr[j]-x))
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        
        for(int l=i;l<=j;l++)
        {
            ans.push_back(arr[l]);
        }
        return ans;
    }
};