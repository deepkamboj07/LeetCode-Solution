class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        if(k==0)
        {
            if(nums1==nums2)return 0;
            return -1;
        }
        
        long long int pos=0,neg=0;
        int n=nums1.size();
        for(int i=0;i<n;i++)
        {
            if(nums1[i] < nums2[i])
            {
                long long int dif=nums2[i]-nums1[i];
                if(dif%k!=0)return -1;
                pos+=(dif);
            }
            else if(nums1[i] > nums2[i])
            {
                long long int dif=nums1[i]-nums2[i];
                if(dif%k!=0)return -1;
                neg+=(dif);
            }
        }
        
       // cout<<pos<<" "<<neg;
        if(pos==neg)return (pos/k);
        return -1;
    }
};