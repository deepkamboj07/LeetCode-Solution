class Solution {
public:
    void merge(vector<int>&nums, int low, int mid, int high)
    {
        int n=mid-low+1;
        int m=high-mid;
        
        vector<int> left;
        vector<int> right;
        
        for(int i=0;i<n;i++)
            left.push_back(nums[low+i]);
        for(int i=0;i<m;i++)
            right.push_back(nums[mid+i+1]);
        
        int i=0,j=0,k=low;
        while(i<n and j<m)
        {
            if(left[i]<=right[j])
            {
                nums[k++]=left[i];
                i++;
            }
            else
            {
                nums[k++]=right[j];
                j++;
            }
        }
        
        while(i<n)
        {
            nums[k++]=left[i++];
        }
        while(j<m)
        {
            nums[k++]=right[j++];
        }
    }
    void mergeSort(vector<int>&nums, int low, int high)
    {
        if(low>=high)return;
        
        int mid=(low+high)>>1;
        mergeSort(nums,low,mid);
        mergeSort(nums,mid+1,high);    
        merge(nums,low,mid,high);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        mergeSort(nums,0,n-1);
        return nums;
    }
};