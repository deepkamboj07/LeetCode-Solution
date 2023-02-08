class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
   
        sort(arr2.begin(), arr2.end());
        
        int ans=0;
        for(int i=0;i<arr1.size();i++)
        {
            int low=0;
            int high=arr2.size()-1;
            
            while(low<=high)
            {
                int mid=(low+high)>>1;
                if(abs(arr2[mid] - arr1[i]) <=d )break;
                
                if(arr2[mid] < arr1[i]) low=mid+1;
                else high=mid-1;
            }
            
            if(low>high)ans++;
        }
        return ans;
    }
};